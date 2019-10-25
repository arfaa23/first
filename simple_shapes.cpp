// Test2019.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>


enum colorShape { colorless = 0, red, green, black };

class iShape
{
	virtual void DrawShape() = 0;
	virtual double GetSquare() = 0;
	virtual colorShape GetColor() = 0;
	virtual void SetColor(colorShape) = 0;
	virtual std::string GetShapeName() = 0;
	virtual void SetShapeName(std::string) = 0;
};

class Shape : public iShape
{
public:
	Shape()
	{
		_shapeColor = colorShape::colorless;
		_shapeName = "";
	}
	virtual ~Shape() 
	{
		std::cout << "delete Shape" << std::endl;
	}


	//interface iShape
	virtual void DrawShape() = 0;
	virtual double GetSquare() = 0;

	colorShape GetColor() override
	{
		return _shapeColor;
	}
	void SetColor(colorShape color) override
	{
		_shapeColor = color;
	}
	void SetShapeName(std::string name)
	{
		_shapeName = name;
	}
	std::string GetShapeName() override
	{
		return _shapeName;
	}
	//interface iShape

protected:
	colorShape _shapeColor;
	std::string _shapeName = "";
};


class Circle : public Shape
{
public:
	Circle(double radius) : Shape()
	{
		_shapeColor = colorShape::red;
		_shapeName = "Circle";
		_radius = radius;
	}

	~Circle()
	{
		std::cout << "delete Circle" << std::endl;
	}

	void DrawShape() override
	{
		std::cout << "  O  " << std::endl;
		std::cout << "O   O" << std::endl;
		std::cout << "O   O" << std::endl;
		std::cout << "  O  " << std::endl;
	}

	double GetSquare() override
	{
		const double PI = 3.14;
		return PI * _radius * _radius;
	}
private:
	int _radius = 0;
};


class Square : public Shape
{
public:
	Square(double line) : Shape()
	{
		_shapeColor = colorShape::green;
		_shapeName = "Square";
		_line = line;
	}

	~Square()
	{
		std::cout << "delete Square" << std::endl;
	}

	void DrawShape() override
	{
		std::cout << "###" << std::endl;
		std::cout << "###" << std::endl;
		std::cout << "###" << std::endl;
	}

	double GetSquare() override
	{
		return  _line * _line;
	}
private:
	int _line = 0;
};

class Triangle : public Shape
{
public:
	Triangle(double line) : Shape()
	{
		_shapeColor = colorShape::black;
		_shapeName = "Triangle";
		_line = line;
	}

	~Triangle()
	{
		std::cout << "delete Triangle" << std::endl;
	}

	void DrawShape() override
	{
		std::cout << " # " << std::endl;
		std::cout << "# #" << std::endl;
		std::cout << "###" << std::endl;
	}

	double GetSquare() override
	{
		return sqrt(3) / 4 * (_line * _line);
	}
private:
	int _line = 0;
};


int main()
{
	Shape* shape;
	//create Circle
	Circle*  shapeCircle = new Circle(3);
	shape = shapeCircle;
	shape->DrawShape();
	std::cout <<  " S = " << shape->GetSquare() << " Name = " << shape->GetShapeName() << std::endl;
	//create Square
	Square* shapeSquare = new Square(3);
	shape = shapeSquare;
	shape->DrawShape();
	std::cout << "S = " << shape->GetSquare() << " Name = " << shape->GetShapeName() << std::endl ;
	//create Triangle
	Triangle* shapeTriangle = new Triangle(2);
	shape = shapeTriangle;
	shape->DrawShape();
	std::cout << "S = " << shape->GetSquare() << " Name = " << shape->GetShapeName() << std::endl;


	delete shapeCircle;
	delete shapeSquare;
	delete shapeTriangle;
	
	return 0;
}