#include <iostream>

using namespace std;

class fraction
{
public:

	fraction(int n = 0, int d = 0);
	void setnum(int);
	void setden(int);
	int getnum();
	int getden();
	fraction operator+(fraction object);
	fraction operator-(fraction object);
	fraction operator/(fraction object);
	fraction operator*(fraction object);

	friend istream &operator>>(istream& input, fraction& f){
		cout << "enter numerator:\n";
		input >> f.num;
		cout << "enter denominator:\n";
		input >> f.den;
		return input;
	}
private:
	int num;
	int den;


};


fraction fraction:: operator+(fraction object) {
	int new_num = num * object.den + den * object.num;
	int new_den = den * object.den;
	return fraction(new_num, new_den);
}
fraction fraction:: operator-(fraction object) {
	int new_num = num * object.den - den * object.num;
	int new_den = den * object.den;
	return fraction(new_num, new_den);
}
fraction fraction:: operator/(fraction object) {
	int just = object.den;
	object.den = object.num;
	object.num = just;
	int new_num = num*object.num;
	int new_den = den * object.den;
	return fraction(new_num, new_den);
}
fraction fraction:: operator*(fraction object) {
	int new_num = num*object.num;
	int new_den = den * object.den;
	return fraction(new_num, new_den);
}

ostream& operator<<(ostream& out, fraction& f){
	out << f.getnum() << "/" << f.getden();
	return out;
}
fraction::fraction(int n, int d){
	num = n;
	den = d;
}


void fraction::setnum(int a)
{
	num = a;
}
void fraction::setden(int a)
{
	den = a;
}
int fraction::getden(){ return den; }
int fraction::getnum(){ return num; }


int main()
{
	fraction a(3, 8);
	cout << a << endl;
	fraction b;
	cin >> b;
	cout << b << endl;
	fraction c = a + b;
	cout << c << endl;
	fraction d = c - a;
	cout << d << endl;
	fraction di = c / a;
	cout << di << endl;
	fraction mul = c*a;
	cout << mul;
	system("pause");
	return 0;
}