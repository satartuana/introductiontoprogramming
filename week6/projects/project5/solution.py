# Project 5 — Mini Shopping Cart
# Author: your name here
# Branch: firstname-project5

menu = {
    1: ("Apple",  0.50),
    2: ("Banana", 0.30),
    3: ("Milk",   1.20),
    4: ("Bread",  2.00),
}

cart = {}
total = 0.0

print("--- Shop Menu ---")
for key, (name, price) in menu.items():
    print(f"{key}. {name:<8} ${price:.2f}")
print("5. Done")

while True:
    choice = input("Choose an item (1-5): ")

    if not choice.isdigit():
        print("Invalid choice.")
        continue

    choice = int(choice)

    if choice == 5:
        break

    if choice not in menu:
        print("Invalid choice.")
        continue

    name, price = menu[choice]

    if name in cart:
        cart[name] += 1
    else:
        cart[name] = 1

    total += price
    print(f"Added {name}. Total: ${total:.2f}")

print("\n--- Receipt ---")

for name, qty in cart.items():
    price = next(p for n, p in menu.values() if n == name)
    print(f"{name:<8} x{qty}   ${price * qty:.2f}")

print("---------------------")
print(f"Total: ${total:.2f}")
print("Thank you!")
