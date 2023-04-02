#include <iostream>
#include<string>
using namespace std;
#include<Windows.h>
#include<vector>

#include"extra.h"
#include"products.h"
#include"adminAndGuests.h"
#include"database.h"

int main()
{
	//	Fake database
	Database data = Database();
	Phone samsung = Phone("Samsung", "S8", 128, 8, "Black", 1500, 2);
	Phone iphone = Phone("Iphone", "14", 512, 4, "Gold", 2500, 3);
	Notebook lenovo = Notebook("Lenovo", "Ideapad", 500,4, "Black", 3000, "HDD");
	Admin admin = Admin("Ismayil", "ismayil123");

	data.products.push_back(&samsung);
	data.products.push_back(&iphone);
	data.products.push_back(&lenovo);
	data.admins.push_back(&admin);

	//	Main menu
	int choiceMainMenu;
	
	while (true)
	{
		system("cls");
		cout << "Choose from menu: \n"
			<< "	Login as user - 1\n"
			<< "	Login as admin - 2\n";
		cin >> choiceMainMenu;

		//	User
		if (choiceMainMenu == 1)
		{
			//	Sum price
			double sumPrice = 0;

			while (true)
			{
				system("cls");

				//	Show products
				for (int i = 0; i < data.products.size(); i++)
				{
					data.products[i]->showSpecifications();
				}

				//	Input ID
				int ID;
				cout << "Please enter ID of product which you want: " << endl;
				cin >> ID;

				//	Search ID in products
				bool find = false;
				int index;
				for (int i = 0; i < data.products.size(); i++)
				{
					if (data.products[i]->get__ID() == ID)
					{
						find = true;
						index = i;
						break;
					}
				}

				//	if program find ID that you entered
				bool stop = false;
				if (find)
				{
					system("cls");
					sumPrice += data.products[index]->get__price();
					cout << "You should pay " << sumPrice << " $" << endl;

					int continueOrStop;
					cout << "For stop - 1\n";
					cin >> continueOrStop;
					if (continueOrStop == 1)
					{
						stop = true;
					}
				}

				//	Stop sale
				if (stop)
				{
					system("cls");
					cout << "You should pay " << sumPrice << " $" << endl;
					Sleep(2000);
					break;
				}

				//	Program can not find ID
				else
				{
					system("cls");
					cout << "Please enter correct ID!" << endl;
					Sleep(2000);
				}
			}
		}

		//	Admin
		else if (choiceMainMenu == 2)
		{
			//	login as admin
			string login, password;
			while (true)
			{
				system("cls");
				cout << "Please enter login, password of admin: " << endl;
				cin >> login, password;

				//	Included admin search in admins
				bool checkAdmin = false;
				for (int i = 0; i < data.admins.size(); i++)
				{
					if (data.admins[i]->get_login() == login)
					{
						if (data.admins[i]->get_password() == password)
						{
							checkAdmin = true;
							break;
						}
					}
				}

				//	If there is included admin in admins
				if (checkAdmin)
				{
					system("cls");

					//	Admin menu
					int adminMenu;
					cout << "Admin menu:" <<
						"\n	1.Show products" <<
						"\n	2.Add product" << endl;
					cin >> adminMenu;

					system("cls");

					//	Show products
					if (adminMenu == 1)
					{
						for (int i = 0; i < data.products.size(); i++)
						{
							data.products[i]->showSpecifications();
						}
						Sleep(2000);
					}

					//	Add products
					else if (adminMenu == 2)
					{
						int productMenu;
						cout << "Create product:\n" <<
							"	1.Create phone\n" <<
							"	2.Create notebook\n";
						cin >> productMenu;

						system("cls");

						string brand="", model="", color = "";
						int storage = 0, RAM = 0;
						double price = 0;

						//	Create phone
						if (productMenu == 1)
						{
							int simCount = 0;
							cout << "Please phone's brand, model, storage, RAM, color, price, simCount: " << endl;
							cin >> brand, model, storage, RAM, color, price, simCount;
							Phone newPhone = Phone(brand, model, storage, RAM, color, price, simCount);
							data.products.push_back(&newPhone);
						}

						//	Create notebook
						else if (productMenu == 2)
						{
							string typeStorage = "";
							cout << "Please phone's brand, model, storage, RAM, color, price, typeStorage: " << endl;
							Notebook newNotebook = Notebook(brand, model, storage, RAM, color, price, typeStorage);
							data.products.push_back(&newNotebook);
						}
					}
				}
			}
		}
		else
		{
			cout << "You can choose only 1 or 2!" << endl;
		}
	}
}
