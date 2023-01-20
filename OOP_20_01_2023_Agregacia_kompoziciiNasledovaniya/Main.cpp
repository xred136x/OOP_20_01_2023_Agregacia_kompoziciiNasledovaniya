#include<iostream>
#include<string>
#include<vector>

// ���������, ���������� � ������������

//class A{
//public:
//	void public_metod(){}
//	//int public_field...
//protected:
//	void protected_metod(){}
//private:
//	void private_metod(){}
//
//};

// private, public, protected

//class B : public A{
//	void func() {
//		protected_metod();
//	}
//
//};

// ����������
// ��������� � ����������
// ���������� - ���� ����� �� ���������� ��� �������(���� ��� ��� ������)
class Engine {
public:
	Engine(int p) : _power(p) {
		std::cout << "Parametrized constructor was calld(Engine)" << '\n';
	}
	Engine(Engine& e) : _power(e._power) {
		std::cout << "Copy constructor was called(Engine)" << '\n';
	}
	int getPower() {
		return _power;
	}
private:
	int _power;
};

//class Car {
//public:
//	// ����������
//	Car(int enginePower): _engine(enginePower) {}
//	// ���������
//	Car(Engine& e) : _engine(e) {}
//
//	int getPower() {
//			return _engine.getPower();
//	}
//	
//private:
//	std::string _model = "Porshe";
//	Engine _engine;// Car ������������ � Engine
//
//};

// ���������� ������������ 
//class Vehicle {
//public:
//	Vehicle(int speed) : _speed(speed) {
//		std::cout << "Vehicle" << '\n';
//	}
//	int getSpeed() {
//		return _speed;
//	}
//private:
//	int _speed;
//};
//enum Transmition {
//	Auto, // �������
//	Manual // �������
//};
//
//class Car : public virtual Vehicle {
//public:
//	Car(int speed, Transmition transmition) : Vehicle(speed), _transmition(transmition){}
//private:
//	Transmition _transmition;
//};
//enum OriginCountry {
//	Russia,
//	UAE
//};
//class Airplane : public virtual Vehicle {
//public:
//	Airplane(int speed, OriginCountry country): Vehicle(speed), _originCountry(country){}
//private:
//	OriginCountry _originCountry;
//};
//
//enum FlyingCarMode {
//	Drive,
//	Fly
//};
//
//class FlyingCar : public Car, Airplane {
//public:
//	FlyingCar(int speed, OriginCountry country, Transmition transmition, FlyingCarMode initialMode) : Car(speed, transmition),
//		Airplane(speed, country), _mode(initialMode), Vehicle(speed) {}
//private:
//	FlyingCarMode _mode;
//};

// ����������� �������
class A {
public:
	// static dispatch / early binding (����������� �����, ������ ��������)
	void foo() {
		std::cout << "A::foo()" << '\n';
	}
};

//class B : public A {
//public:
//	void foo() {
//		std::cout << "B::foo()" << '\n';
//	}
//};
class B{
public:
	virtual void bar() {
		std::cout << "B::bar()" << '\n';
	}
	virtual void qux() {
		std::cout << "B::qux()" << '\n';
	}
};

class C : public B {
public:
	void bar() override {// override - ���������� �������
		std::cout << "C::bar()" << '\n';
	}
};

int main() {

	/*Car c(200);
	std::cout << c.getPower() << '\n';
	Engine e(333);
	std::cout << c.getPower() << '\n';
	Car c2(e);
	std::cout << c2.getPower() << '\n';*/

	// ���������� ������������ 
	//FlyingCar fc(800, OriginCountry::Russia, Transmition::Auto, FlyingCarMode::Fly);
	//std::cout << fc.getSpeed() << '\n';

	//Vehicle* fc2 = new FlyingCar (800, OriginCountry::Russia, Transmition::Auto, FlyingCarMode::Fly);
	//std::cout << fc2->getSpeed() << '\n';

	//delete fc2;

	// ����������� �������

	B* b = new C;
	b->bar();
	return 0;
}