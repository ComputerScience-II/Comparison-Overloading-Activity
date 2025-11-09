
#include <iostream>
#include <cassert>

using namespace std;

class Number {

private:

	int x;

public:

	Number(int a) {
		x = a;
	}

	Number operator+(const Number& y) {
		return Number(this->x + y.x);
	}

	void operator+=(const Number& y) {
		this->x += y.x;
	}

	int get_x() {
		return x;
	}

};

class ComplexNumber {

public:
	int real;
	int im;

	ComplexNumber(int x, int y) {
		real = x;
		im = y;
	}

	ComplexNumber operator+(const ComplexNumber& num) {
		return ComplexNumber(real + num.real, im + num.im);
	}
	ComplexNumber operator-(const ComplexNumber& num) {
		return ComplexNumber(real - num.real, im - num.im);
	}
	ComplexNumber operator*(const ComplexNumber& num) {
		return ComplexNumber(real * num.real - im * num.im, real * num.im + num.real * im);
	}

	bool operator<(const ComplexNumber& num) const {
		if (real < num.real) {
			return true;
		}
		else if (real == num.real) {
			return im < num.im;
		}
		else {
			return false;
		}
		
	}

	bool operator>(const ComplexNumber& num) {

		return num < *this;


	}

	bool operator<=(const ComplexNumber& num) {

		return !(num < *this);

	}

	bool operator>=(const ComplexNumber& num) {

		return !(*this < num);

	}

	bool operator==(const ComplexNumber& num) {

		return !( (*this < num) || (num < *this) );

	}

	bool operator!=(const ComplexNumber& num) {

		return ( (*this < num) || (num < *this) );

	}



	void pretty_print() {
		cout << real << " + " << im << "i" << endl;
	}

};

void testCases() {

	ComplexNumber a = ComplexNumber(1, 2);
	ComplexNumber b = ComplexNumber(2, 3);
	ComplexNumber c = ComplexNumber(1, 3);
	ComplexNumber d = ComplexNumber(1, 2);

	assert(a < b);
	assert(!(b < a));
	assert(a < c);
	assert(!(c < a));
	assert(!(a < d));

	assert(b > a);
	assert(!(a > b));
	assert(c > a);
	assert(!(a > c));
	assert(!(d > a));

	assert(a <= b);
	assert(!(b <= a));
	assert(a <= c);
	assert(!(c <= a));
	assert(a <= d);

	assert(!(b >= a));
	assert(b >= a);
	assert(!(c >= a));
	assert(c >= a);
	assert(d >= a);

	assert(!(a == b));
	assert(!(a == c));
	assert(a == d);

	assert(a != b);
	assert(a != c);
	assert(!(a != d));

	cout << "the operators work!" << endl;
}

int main() {

	ComplexNumber x = ComplexNumber(1, 2);
	ComplexNumber x2 = ComplexNumber(1, 3);
	ComplexNumber x3 = ComplexNumber(1, 1);
	ComplexNumber y = ComplexNumber(5, 8);
	ComplexNumber z = ComplexNumber(0, 1);

	cout << (x < y) << endl;
	cout << (x < x2) << endl;
	cout << (x < x3) << endl;

	x.pretty_print();
	(x * z).pretty_print();
	(x * z * z).pretty_print();
	(x * z * z * z).pretty_print();


}