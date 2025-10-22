🍔 Simple Food Ordering System Using C++

A console-based food ordering application built in C++, designed to simulate a restaurant ordering system.
It allows users to add, edit, delete, view, and order menu items, while maintaining an order history — all handled dynamically using linked lists.

🧠 Overview

This project demonstrates basic data structure and file-free data handling through the use of linked lists to store and manage menu data in memory.
The program features a menu management module for administrators and an ordering system for customers.

It is fully interactive and runs in the console, displaying cleanly formatted menus and order summaries.

✨ Features

🍽️ Menu Management (Admin)

1. Add Menu Item — Add new food or drink with automatic ID generation.
2. Edit Menu Item — Update menu name and price by ID.
3. Delete Menu Item — Remove menu items dynamically.
4. View Menu — Display all available menu items with neatly formatted output.

🛒 Ordering System (Customer)

1. Order Menu Items — Choose menu items by ID to add them to the order list.
2. View Order History — See all ordered items with their total price.
3. Clear Navigation — Users can easily return to the main menu.

⚙️ Other Features

1. Linked List Implementation — All menus and orders are stored using pointers (struct MenuItem).
2. Cross-Platform Clear Screen — Uses system("cls") for Windows and system("clear") for Linux/macOS.
3. Formatted Console Output — Uses <iomanip> to display neat tables.
4. Simple Navigation System — Intuitive main menu and submenus with input validation.

🧭 How to Run
1. Compile the Program Using g++: g++ main.cpp -o foodorder
2. Run the Executable: ./foodorder
3. Follow the On-Screen Menu

Navigate through:

- Master Menu → Add/Edit/Delete/View menu item
- Pesan/Order → Place new orders
- Riwayat Pesanan → View total and ordered items

👥 Developers

Developed by:

1. M. Zainal Ilmi (23081010072)
2. Dhio Rizqi N.S (23081010277)
3. Nasywah Aulia (23081010205)
4. Ailsa Farah (23081010212)

💡 Future Improvements

- Add data persistence using file storage (save/load menu data).
- Implement menu categories (food, drinks, desserts).
- Add login system for admin and customer roles.
- Add colorized console UI.
- Calculate taxes or discounts for orders.
