#include "header.h"
#include "customer_header.h"
#include "shelving_team.h"
#include "functions.h"

void fill_data();
void print_customer_data(const struct Customer *customer);
void fill_cart( struct Customer *customer);
struct Customer customer_info;
extern Config c;  // Declare or include the Config structure
extern Item items[MAX_LINE_LENGTH];
extern int num_items;



int main(int argc, char** argv ) {


    read_items("supermarket_items.txt");
    c = read_config("config.txt");

    fill_data();  // Populate customer_info with data

    printf("\n \n");
    print_customer_data(&customer_info);
    printf("\n \n");

    exit(0);
}




void fill_data(){


    srand(time(NULL));   // for making random choices for each customer

    int r = rand() % 2;      // Returns a pseudo-random integer between 0 and 1.

    // Put the current time as id for the new person
    customer_info.id = getpid();
    customer_info.num_items = 0;
    customer_info.shopping_time= generate_shopping_time();

    fill_cart(&customer_info);

    customer_info.total_price = 0;



}


void print_customer_data(const struct Customer *customer) {

    printf("customer with id %d info is : \n \n",customer->id);

    printf("Customer ID: %d\n", customer->id);
    printf("Number of Items: %d\n", customer->num_items);
    printf("Shopping Time: %d\n", customer->shopping_time);
    printf("Patience Degree: \n ");


    float total = 0.0;
    printf("Items in Cart: ");
    for (int i = 0; i < customer->num_items; ++i) {
        printf(" %s ", items[customer->cart[i]].name);
        total += items[customer->cart[i]].price;


    }

    printf("\nTotal Price: $%.2f\n", total);


}




