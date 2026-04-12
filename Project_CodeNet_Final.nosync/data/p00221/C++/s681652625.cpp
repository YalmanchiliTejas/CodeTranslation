#include<iostream>
#include<string>
#include<vector>
#include<sstream>

std::string toString(int a){
	std::string res;
	std::stringstream z;

	z << a;
	z >> res;

	return res;
}

void setfizzbuzz(std::vector<std::string>&v, int n){

	for (int i = 1; i <= n; i++){
		if (i % 15 == 0)v[i - 1] = "FizzBuzz";
		else if (i % 3 == 0)v[i - 1] = "Fizz";
		else if (i % 5 == 0)v[i - 1] = "Buzz";
		else v[i - 1] = toString(i);

	}

}

int main(){

	int m, n;
	while (std::cin >> m >> n){
		if (m == 0 && n == 0)break;

		std::vector<std::string>fizzbuzz(n);
		std::vector<bool>player(m, true);

		setfizzbuzz(fizzbuzz, n);

		int playnum = m;

		for (int i = 0, pnum = 0; i < n; i++, pnum++){
			if (pnum == m)pnum -= m;
			while (!player[pnum]){
				pnum++;
				if (pnum == m)pnum -= m;
			}

			std::string str;
			std::cin >> str;

			if (playnum != 1 && str != fizzbuzz[i]){
				player[pnum] = false;
				playnum--;
			}
		}

		bool ku = true;
		for (int i = 0; i < player.size(); i++){
			if (player[i]){
				if (ku)std::cout << i + 1, ku = false;
				else std::cout << " " << i + 1;
			}
		}
		std::cout << std::endl;
	}

	return 0;
}