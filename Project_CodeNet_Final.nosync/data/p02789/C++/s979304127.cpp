/* C++14 (Clang 3.8.0) for AtCoder */

#include <iostream>
#include <vector>
#include <string>
// #include <cmath>
// #include <math.h>
// #include <map>
// #include <algorithm>

namespace AtCoder {
	using Str = std::vector<std::string>;
	using Num = std::vector<int>;
	using BigNum = std::vector<double>;

	class Ans {
	public:
		void showResult(void);
		void increment(void);
		void increment(double);
		void decrement(void);
		void decrement(double);
		double getResult(void);
	private:
		double result;
	};
	void Ans::showResult(void) {
		printf("%.0lf\n", this->result);
	}
	void AtCoder::Ans::increment(void) {
		this->result++;
	}
	void AtCoder::Ans::increment(double value) {
		this->result += value;
	}
	void AtCoder::Ans::decrement(void) {
		this->result--;
	}
	void AtCoder::Ans::decrement(double value) {
		this->result -= value;
	}
	double AtCoder::Ans::getResult(void) {
		return this->result;
	}

	void input(Str* str) {
		str->clear();
		std::string buf = "", row = "";
		std::getline(std::cin, buf);
		for (unsigned int i = 0; i < buf.size(); i++) {
			if (' ' == buf[i]) {
				str->push_back(row);
				row = "";
			} else {
				row += buf[i];
			}
		}
		str->push_back(row);
	}
	void input(Num* num) {
		num->clear();
		std::string buf = "", row = "";
		std::getline(std::cin, buf);
		for (unsigned int i = 0; i < buf.size(); i++) {
			if (' ' == buf[i]) {
				num->push_back(std::atoi(row.c_str()));
				row = "";
			} else {
				row += buf[i];
			}
		}
		num->push_back(std::atoi(row.c_str()));
	}
	void input(BigNum* num) {
		num->clear();
		std::string buf = "", row = "";
		std::getline(std::cin, buf);
		for (unsigned int i = 0; i < buf.size(); i++) {
			if (' ' == buf[i]) {
				num->push_back(std::atof(row.c_str()));
				row = "";
			} else {
				row += buf[i];
			}
		}
		num->push_back(std::atof(row.c_str()));
	}
	void exp(std::string* str,  Str* newStr) {
		std::string pre = *str;
		newStr->clear();
		for (unsigned int i = 0; i < pre.length(); i++) {
			newStr->push_back(pre.substr(i, 1));
		}
	}
}

int main(void) {

	AtCoder::Num s;
	AtCoder::input(&s);

	const int a = s[0], b = s[1];

	if (a == b) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}
