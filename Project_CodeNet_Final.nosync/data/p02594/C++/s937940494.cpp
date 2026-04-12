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
	using BigNum = std::vector<long long>;

	class InputData {
	public:
		void getInput(void);
		void skipInput(void);
		Str getStr(void);
		Num getNum(void);
		BigNum getBigNum(void);
	private:
		Str str;
		Num num;
		BigNum bNum;
	};
	Str AtCoder::InputData::getStr(void) {
		return this->str;
	}
	Num AtCoder::InputData::getNum(void) {
		return this->num;
	}
	BigNum AtCoder::InputData::getBigNum(void) {
		return this->bNum;
	}
	void AtCoder::InputData::skipInput(void) {
		std::string buf = "";
		std::getline(std::cin, buf);
	}
	void AtCoder::InputData::getInput(void) {
		this->str.clear();
		this->num.clear();
		this->bNum.clear();

		std::string buf = "", row = "";
		std::getline(std::cin, buf);
		for (unsigned int i = 0; i < buf.size(); i++) {
			if (' ' == buf[i]) {
				this->str.push_back(row);
				this->num.push_back(std::atoi(row.c_str()));
				this->bNum.push_back(std::atoll(row.c_str()));
				row = "";
			} else {
				row += buf[i];
			}
		}
		this->str.push_back(row);
		this->num.push_back(std::atoi(row.c_str()));
		this->bNum.push_back(std::atoll(row.c_str()));
	}

	class Ans {
	public:
		void showResult(void);
		void increment(void);
		void increment(long long);
		void decrement(void);
		void decrement(long long);
		long long getResult(void);
	private:
		long long result;
	};
	void Ans::showResult(void) {
		printf("%lld\n", this->result);
	}
	void AtCoder::Ans::increment(void) {
		this->result++;
	}
	void AtCoder::Ans::increment(long long value) {
		this->result += value;
	}
	void AtCoder::Ans::decrement(void) {
		this->result--;
	}
	void AtCoder::Ans::decrement(long long value) {
		this->result -= value;
	}
	long long AtCoder::Ans::getResult(void) {
		return this->result;
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

	AtCoder::InputData* data = new AtCoder::InputData();
	data->getInput();

	AtCoder::Num num = data->getNum();
	const int x = num[0];

	if (x < 30) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}

	delete(data);

	return 0;
}
