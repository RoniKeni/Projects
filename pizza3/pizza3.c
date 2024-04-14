// Roni Kenigsberg 207106931
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BASIC_PRICE 60.00
#define OLIVES 10
#define MUSHROOMS 12
#define BASIC_SIZE 40
#define TAX 17
#define D_REGULAR 0
#define D_VEGAN 5
#define D_WHOLE_WHEAT 3
#define D_GLUTEN_FREE 4
#define	NONE_PIZZA 0
#define WHOLE_PIZZA 1
#define HALF_PIZZA 0.5
#define QUARTER_PIZZA 0.25
#define DELIVERY 15
struct Pizza
{
	int length; // pizza length (cm)
	int width;  // pizza width (cm)
	char DoughType; // dough type ('r'/'v'/'w'/'f')
	int PlusTax;  // pizza price with tax
	double SizeOlives;// olives amount (0/1/0.5/0.25)
	double SizeMush;// mushrooms amount (0/1/0.5/0.25)
	double price; // pizza price (without tax)
	
};

void main()
{
	int IdNum, HowManyPizza, DoughCost, delivery, payment=0, change, PriceWithTax;
	int tenCoin, fiveCoin = 0, twoCoin = 0, oneCoin = 0, lastDig ;
	int olivesChoice, mushroomsChoice;
	double PriceForDough, PriceForOlive, PriceForMush, ratio,TotalPrice=0;
	struct Pizza pizza;



	
	
	// print a welcome message
	printf("Welcome to MTA-Pizza! \n\n");
	printf("*****\n");
	printf(" ***\n");
	printf("  *\n\n");

	// scan ID's user
	printf("Please enter your ID number:\n");
	scanf("%d", &IdNum);
	printf("\n");

	// print the menu
	printf("Our menu:\n*********\n");
	printf("Basic pizza: %.2lf NIS for %dx%d size pizza\n\n", BASIC_PRICE, BASIC_SIZE, BASIC_SIZE);

	// print topings types
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %d NIS \n", OLIVES);
	printf("Mushrooms: %d NIS \n\n", MUSHROOMS);

	//print dough types
	printf("Dough type for basic size pizza:\n");
	printf("Regular: %d NIS\n", D_REGULAR);
	printf("Vegan: %d NIS\n", D_VEGAN);
	printf("Whole wheat: %d NIS\n", D_WHOLE_WHEAT);
	printf("Gluten free: %d NIS\n\n", D_GLUTEN_FREE);

	//scan the pizza number the user want
	printf("How many pizzas would you like to order?\n");
	scanf("%d", &HowManyPizza);
	
	//check that the number of pizzas is positive
	if (HowManyPizza == 0 ||HowManyPizza < 0) 
	{
		printf("Thank you and goodbye.");
	}

	else
	{
		for (int i = 1; i <= HowManyPizza; i++)
		{
			printf("*************************************************\n");
			printf("Pizza #%d: \n\n", i);
            
		   

			printf("Please enter your pizza's length (cm): ");
			scanf("%d", &pizza.length);
			printf("\n");
            if ((pizza.length%2!=0) || (pizza.length <10) || (pizza.length>40))
			{
				printf("Invalid length! Basic length was chosen as a default.\n");
				pizza.length = BASIC_SIZE;
			}
			printf("\nPlease enter your pizza's width (cm): ");
			scanf("%d", &pizza.width);
			printf("\n");
			

			if ((pizza.width % 2 != 0) || (pizza.width < 10) || (pizza.width > 80))
			{
				printf("Invalid width! Basic width was chosen as a default.\n");
				pizza.width = BASIC_SIZE;
			}
            printf("\n");

			printf("Please enter the pizza's dough type:\n");
			printf("r - for regular\n");
			printf("v - for vegan\n");
			printf("w - for whole wheat\n");
			printf("f - for gluten-free\n");
			scanf(" %c", &pizza.DoughType);
			printf("\n");

			
			switch (pizza.DoughType)
			{
			case 'r':
				DoughCost = D_REGULAR;
				break;
			case 'v':
				DoughCost = D_VEGAN;
				break;
			case 'w':
				DoughCost = D_WHOLE_WHEAT;
				break;
			case 'f':
				DoughCost = D_GLUTEN_FREE;
				break;
			default:
				printf("Invalid choice! Regular dough was chosen as a default.\n");
				DoughCost = D_REGULAR;
				break;

			}
			printf("Please choose the toppings:\n\n");
			printf("Olives (choose 0-3):\n");
			printf("0. None\n");
			printf("1. Whole pizza\n");
			printf("2. Half pizza\n");
			printf("3. Quarter pizza\n");
            scanf("%d", &olivesChoice);
			printf("\n");

			switch (olivesChoice)
			{
			case 0:
				pizza.SizeOlives= NONE_PIZZA;
				break;
			case 1:
				pizza.SizeOlives = WHOLE_PIZZA;
				break;
			case 2:
				pizza.SizeOlives = HALF_PIZZA;
				break;
			case 3:
				pizza.SizeOlives = QUARTER_PIZZA;
				break;
			default:
				printf("Invalid choice! Current topping not added.\n");
				pizza.SizeOlives = NONE_PIZZA;
			}

			

			printf("Mushrooms (choose 0-3):\n");
			printf("0. None\n");
			printf("1. Whole pizza\n");
			printf("2. Half pizza\n");
			printf("3. Quarter pizza\n");
			scanf("%d", &mushroomsChoice);
			printf("\n");

		    switch (mushroomsChoice)
			{
			case 0:
				pizza.SizeMush = NONE_PIZZA;
				break;
			case 1:
				pizza.SizeMush = WHOLE_PIZZA;
				break;
			case 2:
				pizza.SizeMush = HALF_PIZZA;
				break;
			case 3:
				pizza.SizeMush = QUARTER_PIZZA;
				break;
			default:
				printf("Invalid choice! Current topping not added.\n");
				pizza.SizeMush = NONE_PIZZA;
			}	

			if ((pizza.SizeMush+pizza.SizeOlives) > 1)
			{
				printf("You have exceeded the maximum amount of toppings allowed on one pizza! Current topping not added.\n");
				pizza.SizeMush = NONE_PIZZA;
			}

			ratio = (pizza.length * pizza.width) / (double)(BASIC_SIZE * BASIC_SIZE);
			PriceForDough = ratio * DoughCost;
			PriceForOlive = ratio * pizza.SizeOlives * OLIVES;
			PriceForMush = ratio * pizza.SizeMush * MUSHROOMS;
			pizza.price = (ratio * BASIC_PRICE) + PriceForDough + PriceForOlive + PriceForMush;

			TotalPrice = TotalPrice + pizza.price;
			
			
			printf("Pizza #%d details:\n*******************\n", i);
			printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
			printf("Pizza price (without tax): %.2lf\n", pizza.price);

		}
		
		printf("*************************************************\n");
		printf("Do you want delivery for the price of 15 NIS? Enter 1 for delivery or 0 for pick-up:");
		scanf("%d", &delivery);
		printf("\n");

		if ((delivery != 0) && (delivery != 1))
		{
			printf("Invalid choice! Pick-up was chosen as a default.\n");
			delivery = NONE_PIZZA;
		}
		TotalPrice = TotalPrice + (delivery * DELIVERY);
        
		printf("Your order details:\n*******************\n");
		printf("ID number: %09d\n", IdNum);
		printf("Number of pizzas: %d\n", HowManyPizza);
		printf("Total price: %.2lf\n", (TotalPrice));
        PriceWithTax = (TotalPrice + (TotalPrice * TAX) / 100);
		printf("Total price with tax (rounded down): %d\n",PriceWithTax);
		printf("Please enter your payment: \n");
		scanf("%d", &payment);
		while (payment < PriceWithTax)
		{
			PriceWithTax -= payment;
			printf("Your remaining balance is: %d\n", PriceWithTax);
			printf("Please enter your payment: ");
			scanf("%d", &payment);
		}

		change = payment - PriceWithTax;
		tenCoin = change / 10;
		lastDig = change % 10;
		if (lastDig >= 5)
		{
			fiveCoin++;
			lastDig -= 5;
		}
		while (lastDig >= 2)
		{
			twoCoin++;
			lastDig -= 2;
		}
		while (lastDig > 0)
		{
			oneCoin++;
			lastDig -= 1;
		}
		if (change > 0)
			printf("Your change is %d NIS using:\n", change);
		if (tenCoin > 0)
			printf("%d coin(s) of ten\n", tenCoin);
		if (fiveCoin > 0)
			printf("%d coin(s) of five\n", fiveCoin);
		if (twoCoin > 0)
			printf("%d coin(s) of two\n", twoCoin);
		if (oneCoin > 0)
			printf("%d coin(s) of one\n", oneCoin);
		printf("Thank you for your order!\n");



	}
}
