// GroceryItem.cpp
#include "GroceryItem.h"

GroceryItem::GroceryItem(std::string& name) : name(name), quantity(1) {}

GroceryItem::GroceryItem(std::string& name, int quantity) : name(name), quantity(quantity) {}

// Function to get the name of the grocery item.
std::string GroceryItem::getName() const
{
    return name;
}

// Function to get the quantity of the grocery item.
int GroceryItem::getQuantity() const
{
    return quantity;
}

// Function to increase the quantity of the grocery item by 1.
void GroceryItem::addItem()
{
    quantity++;
}

// Function to decrease the quantity of the grocery item by 1, ensuring it doesn't go below 0.
void GroceryItem::removeItem()
{
    if (quantity > 0)
        quantity--;
}

// Overloaded '<' operator to compare two GroceryItem objects based on their names.
bool GroceryItem::operator<(const GroceryItem& other) const
{
    return name.compare(other.getName()) < 0;
}