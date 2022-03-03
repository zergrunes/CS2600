/**
 * CS 2600 Quiz 1
 * @file restaurant_bill.c
 * @Marian Remoroza 
 * @version 0.1
 * @date 2022-03-02
 */
/**
 * stdio.h for input/output functions
 * time.h for the rng
 * stdlib.h for conversion
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[]){

    // Asking for user input
    printf("\nGot a problem calculating your restaurant bill? Look no more and use our calculator.\n"
           "Please enter the restaurant tax and your tip as percentages in this form:\n "
           "./restaurant_bill (tax) (tip)\n"
           "NOTE: We accept tax rates > 0 and tips >= 0.\n");

    // Input validation
    if (argc != 3){
        printf("\nERROR:\n Please enter the restaurant tax and your tip:\n"
               "./restaurant_bill.out (tax) (tip)\n");
    } else{
        printf("\nMENU:\n"
               "Salad: $9.95\n"
               "Soup: $4.55\n"
               "Sandwich: $13.25\n"
               "Pizza: $22.35\n");

        // initializing enum for the meals so it's easier to work with
        char *meal[4]={"Salad","Soup","Sandwich","Pizza"};
        double price[4]={9.95,4.55,13.25,22.35};

       // for the rng
        int rand_meal = 0;
        time_t t;

        srand(time(&t));
       // we initialized char *meal to 4 so we can do the % operation when finding a random num
        rand_meal = rand() % 4;

        printf("\nWe got our randomizer choose your meal for you\n%s: ", meal[rand_meal]);
        printf(" $%.2f\n", price[rand_meal]);

        double mealPrice = price[rand_meal];
        double tax = mealPrice*(atof(argv[1])/100);
        double tip = mealPrice*(atof(argv[2])/100);

        printf("Tax Amount: $%.2f ",tax);
        printf("(%s%%)\n", argv[1]);
        printf("Tip Amount: $%.2f ", tip);
        printf("(%s%%)\n", argv[2]);

        printf("TOTAL BILL:\n"
               "$%.2f\n",mealPrice+tax+tip);
    }  
    return 0;
}

