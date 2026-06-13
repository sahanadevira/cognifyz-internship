//INVENTORY MANAGEMENT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
    int next_id;
} Inventory;

void init_inventory(Inventory *inv) {
    inv->count = 0;
    inv->next_id = 1;
}

void add_item(Inventory *inv, char *name, int quantity, float price) {
    if (inv->count >= MAX_ITEMS) {
        printf("\nInventory is full!\n");
        return;
    }
    Item *item = &inv->items[inv->count];
    item->id = inv->next_id++;
    strncpy(item->name, name, MAX_NAME - 1);
    item->name[MAX_NAME - 1] = '\0';
    item->quantity = quantity;
    item->price = price;
    inv->count++;
    printf("\nItem '%s' added successfully with ID %d.\n", name, item->id);
}

void display_items(Inventory *inv) {
    if (inv->count == 0) {
        printf("\nInventory is empty.\n");
        return;
    }
    printf("\n Current Inventory:\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < inv->count; i++) {
        Item *item = &inv->items[i];
        printf("ID: %d | Name: %s | Qty: %d | Price: $%.2f\n",
               item->id, item->name, item->quantity, item->price);
    }
    printf("-------------------------------------------------------\n");
}

void search_by_name(Inventory *inv, char *name) {
    int found = 0;
    printf("\nSearch results for '%s':\n", name);
    for (int i = 0; i < inv->count; i++) {
        if (strstr(inv->items[i].name, name) != NULL) {
            Item *item = &inv->items[i];
            printf("ID: %d | Name: %s | Qty: %d | Price: $%.2f\n",
                   item->id, item->name, item->quantity, item->price);
            found = 1;
        }
    }
    if (!found) {
        printf(" No items found with name '%s'.\n", name);
    }
}

void search_by_id(Inventory *inv, int id) {
    for (int i = 0; i < inv->count; i++) {
        if (inv->items[i].id == id) {
            Item *item = &inv->items[i];
            printf("\nItem found:\n");
            printf("ID: %d | Name: %s | Qty: %d | Price: $%.2f\n",
                   item->id, item->name, item->quantity, item->price);
            return;
        }
    }
    printf("\n No item found with ID %d.\n", id);
}

int main() {
    Inventory inv;
    init_inventory(&inv);

    int choice;
    char name[MAX_NAME];
    int quantity, id;
    float price;

    while (1) {
        printf("\n============================\n");
        printf("  Inventory Management Menu\n");
        printf("============================\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search by Name\n");
        printf("4. Search by ID\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                getchar();
                add_item(&inv, name, quantity, price);
                break;

            case 2:
                display_items(&inv);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = '\0';
                search_by_name(&inv, name);
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                getchar();
                search_by_id(&inv, id);
                break;

            case 5:
                printf("\nExiting...\n");
                return 0;
                default:
                printf("\nInvalid choice. Please select 1-5.\n");
        }
    }

    return 0;
