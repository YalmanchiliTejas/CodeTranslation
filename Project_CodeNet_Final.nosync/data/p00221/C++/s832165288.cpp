#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <list>
#define MAX_M 1000
#define MAX_N 10000

using namespace std;

int atoi(string s){
	int res = 0;
	for(int i = 0;i < s.size();i++){
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}


int main(void){
	int n, m;
	list<int> sur; // 生き残りプレイヤー番号
	
	string s;
	while(1){
		cin >> m >> n;
		if(m == 0 && n == 0){
			break;
		}
		for(int i = 0;i < m;i++){
			sur.push_back(i + 1);
		}

		list<int>::iterator it = sur.begin(), next = sur.begin();
		next++;
		for(int i = 1;i <= n;i++){
			cin >> s;
			if(sur.size() == 1){
				continue;;
			}

			if(i % 15 == 0 && s == "FizzBuzz"){
				it++;
				next++;
			}else if(i % 15 != 0 && i % 5 == 0 && s == "Buzz"){
				it++;
				next++;
			}else if(i % 15 != 0 && i % 3 == 0 && s == "Fizz"){
				it++;
				next++;
			}else if(i % 3 != 0 && i % 5 != 0 && i % 15 != 0 && s != "FizzBuzz" && s != "Buzz" && s != "Fizz" && atoi(s) == i){
				it++;
				next++;
			}else{
				sur.erase(it);
				it = next;
				next++;
			}
			if(sur.end() == next){
				next = sur.begin();
			}
			if(sur.end() == it){
				it = sur.begin();
			}
		}
		it = sur.begin();
		for(int i = 0;i < sur.size();i++){
			if(i != 0){
				cout << " ";
			}
			cout << *it;
			it++;
		}
		cout << endl;
		sur.clear();

	}
	return 0;
}