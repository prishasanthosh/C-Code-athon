#include <stdio.h>
struct Product {
char name[50];
int quantity;
float price;
int id;
};
void addProduct(struct Product *inventory, int *count)
{
printf("Enter product name: ");
scanf("%s", inventory[*count].name);
printf("Enter product quantity: ");
scanf("%d", &inventory[*count].quantity);
printf("Enter product price: ");
scanf("%f", &inventory[*count].price);
printf("Enter product id: ");
scanf("%d",&inventory[*count].id);
(*count)++;
}
void displayInventory(struct Product *inventory, int count)
{
printf("\nInventory Information:\n");
for (int i = 0; i < count; ++i) {
printf("Name: %s, Quantity: %d, Price: %.2f\n, Product id: %d", inventory[i].name, inventory[i].quantity, inventory[i].price, inventory[i].id);
}
}
int main() {
struct Product inventory[100];
int productCount = 0;
int x,pro,qty,amt;
while(1){
printf("1.Admin\n2.Customer\n3.Exit\n");
printf("Enter your choice :");
scanf("%d",&x);
if(x==1) {
printf("\nInventory Management System Menu:\n");
printf("1. Add Product\n");
printf("2. Display Inventory\n");
printf("3. Exit\n");
int choice;
printf("Enter your choice (1-3): ");
scanf("%d", &choice);
switch (choice) {
case 1:
addProduct(inventory, &productCount);
break;
case 2:
displayInventory(inventory, productCount);
break;
case 3:
printf("Exiting Inventory Management System.\n");
return 0;
default:
printf("Invalid choice. Please enter a number between 1 and 3.\n");
}
}
else if (x == 2) {
int j, i;
printf("1. View products\n");
displayInventory(inventory, productCount);
printf("\nEnter your product ID: ");
scanf("%d", &pro);
printf("Enter your quantity: ");
scanf("%d", &qty);
// Find the index of the selected product
for (i = 0; i < productCount; i++) {
if (inventory[i].id == pro) {
j = i;
break;
}
}
if (i == productCount) {
printf("Product with ID %d not found.\n", pro);
} else {
printf("Price: %.2f\n", inventory[j].price);
printf("Total amount: %.2f\n", qty * inventory[j].price);
}
}
else{
printf("Exiting Inventory Management System.\n");
return 0;
}
continue;
}
return 0;
}