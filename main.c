// Program: Inventory Control System
// Description: A program that allows a business to keep track of inventory and profits.
// Programmer: Manjinder Singh

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 12
#define FILE_NAME "inventory.txt"

// Structure definition for each item
struct Item
{
    char name[20];
    int id;
    float cost;
    int stock;
    int sold;
    float profit;
};

// Structure definition for the inventory
struct Inventory
{
    struct Item items[MAX_ITEMS];
    float totalProfit;
};

// Function prototypes
void displayMenu();
void loadInventory(struct Inventory *inventory);
void saveInventory(const struct Inventory *inventory);
void showItems(const struct Inventory *inventory);
void sellItem(struct Inventory *inventory);
void showSales(const struct Inventory *inventory);
void orderItem(struct Inventory *inventory);
void orderNewItems(struct Inventory *inventory);
void explanation();

// Main function
int main()
{
    explanation();

    struct Inventory inventory;
    loadInventory(&inventory);

    char choice;
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            showItems(&inventory);
            break;
        case 'b':
            sellItem(&inventory);
            break;
        case 'c':
            showSales(&inventory);
            break;
        case 'd':
            orderItem(&inventory);
            break;
        case 'e':
            orderNewItems(&inventory);
            break;
        case 'f':
            saveInventory(&inventory);
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 'f');

    return 0;
}

// Function to display the menu options
void displayMenu()
{
    printf("\nInventory Control System\n");
    printf("\nTo choose a function, enter its letter label:\n");
    printf("a) Show the name, identification number, and quantity of each item in stock, including the cost of each item and total value of each item in stock.\n");
    printf("b) Allow the owner to enter the sale of an item.\n");
    printf("c) Show the number of units of each type sold, profit of each item, and total profit.\n");
    printf("d) Allow the owner to order more of an existing item.\n");
    printf("e) Allow the owner to order new items.\n");
    printf("f) Quit.\n");
}

// Function to load inventory data from a file
void loadInventory(struct Inventory *inventory)
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file != NULL)
    {
        fread(inventory, sizeof(struct Inventory), 1, file);
        fclose(file);
    }
    else
    {
        // Initialize inventory with default values if the file doesn't exist
        memset(inventory, 0, sizeof(struct Inventory));
    }
}

// Function to save inventory data to a file
void saveInventory(const struct Inventory *inventory)
{
    FILE *file = fopen(FILE_NAME, "w");
    if (file != NULL)
    {
        fwrite(inventory, sizeof(struct Inventory), 1, file);
        fclose(file);
    }
    else
    {
        printf("Failed to save inventory to file.\n");
    }
}

// Function to display items in stock
void showItems(const struct Inventory *inventory)
{
    printf("\nInventory Control System\n\n");
    printf("Item Name    Id Number    Quantity    Unit Cost    Value\n");

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        const struct Item *item = &inventory->items[i];
        if (item->id != 0)
        {
            float value = item->cost * item->stock;
            printf("%-12s %-12d %-12d $%-11.2f $%.2f\n", item->name, item->id, item->stock, item->cost, value);
        }
    }
}

// Function to sell an item
void sellItem(struct Inventory *inventory)
{
    int itemId, quantity;
    printf("Enter the item ID: ");
    scanf("%d", &itemId);
    printf("Enter the quantity sold: ");
    scanf("%d", &quantity);

    struct Item *item = NULL;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (inventory->items[i].id == itemId)
        {
            item = &inventory->items[i];
            break;
        }
    }

    if (item == NULL)
    {
        printf("Item with ID %d not found.\n", itemId);
        return;
    }

    if (item->stock < quantity)
    {
        printf("Not enough stock available.\n");
        return;
    }

    float sellingPrice = item->cost * 1.5f;
    float profit = sellingPrice * quantity;
    item->stock -= quantity;
    item->sold += quantity;
    item->profit += profit;
    inventory->totalProfit += profit;

    printf("Sale processed successfully.\n");
}

// Function to display sales information
void showSales(const struct Inventory *inventory)
{
    printf("\nInventory Control System\n\n");
    printf("Item Name    Id Number    Quantity Sold    Item Profit\n");

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        const struct Item *item = &inventory->items[i];
        if (item->id != 0 && item->sold > 0)
        {
            printf("%-12s %-12d %-16d $%.2f\n", item->name, item->id, item->sold, item->profit);
        }
    }

    printf("\nTotal Profit: $%.2f\n", inventory->totalProfit);
}

// Function to order more of an existing item
void orderItem(struct Inventory *inventory)
{
    int itemId, quantity;
    printf("Enter the item ID: ");
    scanf("%d", &itemId);
    printf("Enter the quantity to order: ");
    scanf("%d", &quantity);

    struct Item *item = NULL;
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (inventory->items[i].id == itemId)
        {
            item = &inventory->items[i];
            break;
        }
    }

    if (item == NULL)
    {
        printf("Item with ID %d not found.\n", itemId);
        return;
    }

    item->stock += quantity;
    printf("Order placed successfully.\n");
}

// Function to order new items
void orderNewItems(struct Inventory *inventory)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        struct Item *item = &inventory->items[i];
        if (item->id == 0)
        {
            printf("Enter the name of the new item: ");
            scanf("%s", item->name);
            printf("Enter the item ID: ");
            scanf("%d", &item->id);
            printf("Enter the cost of the item: ");
            scanf("%f", &item->cost);
            printf("Enter the initial stock quantity: ");
            scanf("%d", &item->stock);
            break;
        }
    }

    printf("New item added successfully.\n");
}

void explanation()
{
    printf("Program: Inventory Control System\n");
    printf("Description: A program that allows a business to keep track of inventory and profits.\n");
    printf("Programmer: Manjinder Singh\n\n");
}
