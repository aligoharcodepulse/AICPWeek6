#include <iostream>
using namespace std;
int main()
{
	cout << "\t\t\t\t\t    Main Menu\n";
	cout << "\t\t-------------------------------------------------------------------\n";
	cout << "\t\t|    SYMBOLS\t|    ITEMS \t|     WEIGHTS\t    |   PRICES     |\n";
	cout << "\t\t|\t\t|\t\t|\t\t    |\t\t   |\n";
	cout << "\t\t|     C\t\t|    Cement \t| 24.9KG to 25.1KG  |\t  3$\t   |\n";
	cout << "\t\t|     S\t\t|    Sand \t| 49.9KG to 50.1KG  |\t  2$\t   |\n";
	cout << "\t\t|     G\t\t|    Gravel\t| 49.9KG to 50.1KG  |\t  2$\t   |\n";
	cout << "\t\t-------------------------------------------------------------------\n\n";
	int c_sack, g_sack, s_sack, price, total_order, reject = 0;
	float total_weight = 0.0 , weight{};

	cout << "\t\tEnter the number of cement sacks: ";
	cin >> c_sack;

	cout << "\t\tEnter the number of gravel sacks: ";
	cin >> g_sack;

	cout << "\t\tEnter the number of sand sacks: ";
	cin >> s_sack;

	price= (c_sack * 3) + (g_sack * 2) + (s_sack * 2);
	total_order = c_sack + g_sack + s_sack;

	for (int count = 1; count <= total_order; ++count) {
		char content;
		cout << "\t\tEnter the content of a sack, C for cement, G for gravel, and S for sand: ";
		cin >> content;

		if (content == 'C') {
			while (true) {
				cout << "\t\tEnter weight of cement sack between 24.9KG and 25.1KG: ";
				cin >> weight;
				if (weight >= 24.9 && weight <= 25.1) {
					break;
				}
				else if (weight < 24.9) {
					cout << "\t\tSack is underweight" << endl;
					reject += 1;
				}
				else {
					cout << "\t\tSack is overweight" << endl;
					reject += 1;
				}
			}
		}
		else if (content == 'G' || content == 'S') {
			while (true) {
				cout << "\t\tEnter weight of " << content << " sack between 49.9KG and 50.1KG: ";
				cin >> weight;
				if (weight >= 49.9 && weight <= 50.1) {
					break;
				}
				else if (weight < 49.9) {
					cout << "\t\tSack is underweight" << endl;
					reject += 1;
				}
				else{
					cout << content << "\t\tsack is overweight" << endl;
					reject += 1;
				}
			}
		}
		else
		{
			cout << "\t\tYou Entered Invalid Content!" << endl;
		}
		total_weight += weight;
	}
	cout << "\t\tTotal weight of order is: " << total_weight << endl;
	cout << "\t\tThe number of sacks rejected are: " << reject << endl;

	int sp = 0, sp_price = 0;//sp stands for Special Pack
	int discount_price, total_discount;

	while (c_sack >= 1 && g_sack >= 2 && s_sack >= 2) {
		sp += 1;
		c_sack -= 1;
		g_sack -= 2;
		s_sack -= 2;
	}
	if (sp >= 1) {
		sp_price = sp * 10;
		cout << "\t\tTotal special packs are: " << sp << endl;
		cout << "\t\tPrice of special packs in dollars is: $" << sp_price << endl;

		discount_price = (c_sack * 3) + (g_sack * 2) + (s_sack * 2) + sp_price;
		cout << "\t\tThe Price of order is: $" << price << endl;
		cout << "\t\tThe price of order after discount is: $" << discount_price << endl;

		total_discount = price - discount_price;
		cout << "\t\tTotal discount in order is: $" << total_discount << endl;
	}
	else {
		std::cout << "\t\tPrice of regular order in dollars is: $" << price << std::endl;
	}
	return 0;
}