#pragma once

class Product
{

protected:
	static int __staticID;
	int __ID;
	string __brand;
	string __model;
	short __storage;
	short __RAM;
	string __color;
	double __price;

	string __category;

public:

	//	Get ID of class
	const int get__ID() const noexcept
	{
		return this->__ID;
	}

	//	Encapsulation of brand
	const string get__brand() const noexcept
	{
		return this->__brand;
	}
	void set__brand(const string brand)
	{
		try
		{
			//	Check sent brand
			if (brand == "")
			{
				throw Error("Sent brand can not be empty!", __TIME__, __LINE__);
			}

			this->__brand = brand;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of model
	const string get__model() const noexcept
	{
		return this->__model;
	}
	void set__model(const string model)
	{
		try
		{
			//	Check sent model
			if (model == "")
			{
				throw Error("Sent model can not be empty!", __TIME__, __LINE__);
			}

			this->__model = model;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of storage
	const short get__storage() const noexcept
	{
		return this->__storage;
	}
	void set__storage(const short storage)
	{
		try
		{
			//	Check sent storage
			if (storage < 0 || storage > 1024)
			{
				throw Error("Sent storage can not be less than zero and more then 64!", __TIME__, __LINE__);
			}

			this->__storage = storage;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of RAM
	const short get__RAM() const noexcept
	{
		return this->__RAM;
	}
	void set__RAM(const short RAM)
	{
		try
		{
			//	Check sent RAM
			if (RAM < 0 || RAM > 64)
			{
				throw Error("Sent RAM can not be less than zero and more than 64!", __TIME__, __LINE__);
			}

			this->__RAM = RAM;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of color
	const string get__color() const noexcept
	{
		return this->__color;
	}
	void set__color(const string color)
	{
		try
		{
			//	Check sent color
			if (color == "")
			{
				throw Error("Sent color con not be empty!", __TIME__, __LINE__);
			}

			this->__color = color;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Encapsulation of price
	const double get__price() const noexcept
	{
		return this->__price;
	}
	void set__price(const double price)
	{
		try
		{
			//	Check sent price
			if (price < 0)
			{
				throw Error("Price can not be less than zero!", __TIME__, __LINE__);
			}

			this->__price = price;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Get method of category
	const string get__category() const noexcept
	{
		return this->__category;
	}

	//	Constructor with parameters
	Product(const string brand, const string model, const short storage,
		const short RAM, const string color, const double price)
	{
		__ID = ++(__staticID);
		set__brand(brand);
		set__model(model);
		set__storage(storage);
		set__RAM(RAM);
		set__color(color);
		set__price(price);
	}

	//	Show phone's specifications
	virtual void showSpecifications() const noexcept = 0
	{
		cout << "ID: " << this->__ID
			<< "\nBrand: " << this->__brand
			<< "\nModel: " << this->__model
			<< "\nStorage: " << this->__storage<<" GB"
			<< "\nRam: " << this->__RAM<<" GB"
			<< "\nColor: " << this->__color
			<< "\nCategory: " << this->__category
			<< "\nPrice: " << this->__price << endl;
	}
	
};

int Product::__staticID = 0;

class Phone : public Product
{

protected:

	short __simCount;

public:

	//	Encapsulation of sizeCount
	const short get__simCount() const noexcept
	{
		return this->__simCount;
	}
	void set__simCount(const short simCount)
	{
		try
		{
			//	Check sent size
			if (simCount < 0 || simCount > 3)
			{
				throw Error("Sim's count can not be less than zero and more than 3!", __TIME__, __LINE__);
			}

			this->__simCount = simCount;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Constructor with parameters	
	Phone(const string brand, const string model, const short storage,
		const short RAM, const string color, const double price, const short simCount)
		: Product(brand, model, storage, RAM, color, price)
	{
		this->__category = "Phone";
		set__simCount(simCount);
	}

	//	Show phone's specifications
	void showSpecifications()  const noexcept override
	{
		Product::showSpecifications();
		cout << "Sim count: " << this->__simCount << endl << endl;
	}

};

class Notebook : public Product
{

protected:
	
	string __typeStorage;
	
public:

	//	Encapsulation of typeStorage
	const string get__typeStorage() const noexcept
	{
		return this->__typeStorage;
	}
	void set__typeStorage(const string typeStorage)
	{
		try
		{
			//	Check sent typeStorage
			if (typeStorage != "HDD" && typeStorage != "SSD")
			{
				throw Error("Sent typeStorage can be only HDD or SSD!", __TIME__, __LINE__);
			}

			this->__typeStorage = typeStorage;

		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	//	Constructor with parameters
	Notebook(const string brand, const string model, const short storage,
		const short RAM, const string color, const double price, const string typeStorage)
		: Product(brand, model, storage, RAM, color, price)
	{
		this->__category = "Notebook";
		set__typeStorage(typeStorage);
	}

	//	Show notebook's specifications
	void showSpecifications()  const noexcept override
	{
		Product::showSpecifications();
		cout << "Storage's type: " << this->__typeStorage<<endl<<endl;
	}

};