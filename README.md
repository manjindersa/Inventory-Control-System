# Inventory Control System

## Description
The Inventory Control System is a simple C program that allows a business to keep track of inventory and profits. It provides functionality to display items, record sales, show sales data, order existing items, and add new items to the inventory.

## Features
- **Display Inventory**: Shows the name, ID, quantity, cost, and total value of each item in stock.
- **Record Sales**: Allows the user to record the sale of an item, updating the stock and profit accordingly.
- **Show Sales Data**: Displays the number of units sold, profit per item, and total profit.
- **Order Existing Items**: Allows the user to order more of an existing item.
- **Add New Items**: Enables the user to add new items to the inventory.
- **Save and Load Inventory**: Saves the current inventory to a file and loads it at startup.

## Usage
1. **Compile the Program**: Use a C compiler to compile the program.
    ```sh
    gcc -o inventory-control-system main.c
    ```
2. **Run the Program**: Execute the compiled program.
    ```sh
    ./inventory-control-system
    ```
3. **Menu Options**:
    - `a`: Show inventory items.
    - `b`: Record a sale.
    - `c`: Show sales data.
    - `d`: Order more of an existing item.
    - `e`: Add new items.
    - `f`: Quit the program.

## Program Structure

### Main Function
- Initializes the inventory.
- Loads inventory data from a file.
- Displays a menu to interact with the user.

### Functions
- **displayMenu**: Displays the main menu options.
- **loadInventory**: Loads inventory data from a file.
- **saveInventory**: Saves inventory data to a file.
- **showItems**: Displays all items in the inventory.
- **sellItem**: Records the sale of an item and updates stock and profit.
- **showSales**: Displays sales data including items sold and profits.
- **orderItem**: Allows ordering more of an existing item.
- **orderNewItems**: Adds new items to the inventory.
- **explanation**: Prints the program's title and description.

### Data Structures
- **Item**: Represents an individual inventory item.
    ```c
    struct Item {
        char name[20];
        int id;
        float cost;
        int stock;
        int sold;
        float profit;
    };
    ```
- **Inventory**: Represents the inventory containing multiple items and the total profit.
    ```c
    struct Inventory {
        struct Item items[MAX_ITEMS];
        float totalProfit;
    };
    ```

## File Handling
- The inventory data is stored in a file named `inventory.txt`.
- On startup, the program attempts to load data from this file. If the file does not exist, it initializes an empty inventory.
- The inventory data is saved to this file when the program exits.

## Author
- **Manjinder Singh**

---

Feel free to contribute, report issues, or suggest features by opening a pull request or issue on the [GitHub repository](https://github.com/manjindersa/inventory-control-system).
