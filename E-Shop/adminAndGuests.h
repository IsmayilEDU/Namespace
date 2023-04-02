#pragma once

class User
{

private:

	string _name;
	string _surname;

public:

	//	Encapsulation of name
	const string get_name() const noexcept
	{
		return this->_name;
	}
	void set_name(const string name)
	{
		try
		{
			//	Check sent user's name
			if (name == "")
			{
				throw Error("Name can not be empty!", __TIME__, __LINE__);
			}

			this->_name = name;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of surname
	const string get_surname() const noexcept
	{
		return this->_surname;
	}
	void set_surname(const string surname)
	{
		try
		{
			//	Check sent user's surname
			if (surname == "")
			{
				throw Error("Sent user's surname can not be empty!", __TIME__, __LINE__);
			}

			this->_surname = surname;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Constructor with parameters
	User(const string name, const string surname)
	{
		set_name(name);
		set_surname(surname);
	}
};

class Admin
{

private:

	string _login;
	string _password;

public:

	//	Encapsulation of login
	const string get_login() const noexcept
	{
		return this->_login;
	}
	void set_login(const string login)
	{
		try
		{
			//	Check sent login
			if (login == "")
			{
				throw Error("Login cna not be empty!", __TIME__, __LINE__);
			}

			this->_login = login;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of password
	const string get_password() const noexcept
	{
		return this->_password;
	}
	void set_password(const string password)
	{
		try
		{
			if (password.size() >= 8)
			{
				throw Error("Password's lenght should be minimum 8 characters!", __TIME__, __LINE__);
			}

			this->_password = password;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Constructor with parameters
	Admin(const string login, const string password)
	{
		set_login(login);
		set_password(password);
	}

	//	Add product
	void addProduct(vector<Product*> products, Product& product)
	{
		products.push_back(&product);
	}

	//	Show all products
	void showProducts(vector<Product*> products)
	{
		for (int i = 0; i < products.size(); i++)
		{
			products[i]->showSpecifications();
		}
	}

	//	Delete product from products (by ID)
	void deleteProductByID(vector<Product*> products, int id)
	{
		for (int i = 0; i < products.size(); i++)
		{
			if (products[i]->get__ID() == id)
			{
				delete products[i];
			}
		}
	}
};