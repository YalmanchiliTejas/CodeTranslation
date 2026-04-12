/*
g++ -std=c++11 -Wall -O2 -o main.exe main.cpp
./main.exe
*/

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
//intの最大値: INT_MAX
//longの最大値: LONG_MAX
//long longの最大値: LLONG_MAX
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
//最大公約数: gcd()
//最小公倍数: lcm()

#define ll long long int

using namespace std;

template <typename T>
string itos(T val){ //数値を文字列(string)に変換
	stringstream ss;

	ss << val;
	return ss.str();
}

int stoi(string s){ //文字列(string)を数値に変換
	stringstream ss;
	int val = 0;

	ss << s;
	ss >> val;
	return val;
}

template <typename T>
void sortasc(vector<T> &v){ //vectorを昇順にソート
    sort(v.begin(), v.end(), std::less<T>());
    return;
}

template <typename T>
void sortdesc(vector<T> &v){ //vectorを降順にソート
    sort(v.begin(), v.end(), std::greater<T>());
    return;
}

//------------------------------------------------------------------------------

int main(){
	int h, w;
	cin >> h >> w;

	vector<string> s(h);
	vector<bool> flag(w, true);
	bool flag2 = true;

	for(int i = 0; i < h; i++){
		cin >> s[i];
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(s[i][j] != '.'){
				flag2 = false;
				break;
			}
		}
		if(flag2){
			s.erase(s.begin() + i);
			h--;
			i--;
		}
		flag2 = true;
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(s[i][j] != '.'){
				flag[j] = false;
			}
		}
	}

	for(int i = 0; i < w; i++){
		if(flag[i]){
			flag.erase(flag.begin() + i);

			for(int j = 0; j < h; j++){
				s[j].erase(i, 1);
			}

			i--;
			w--;
		}
	}

	for(int i = 0; i < s.size(); i++){
		cout << s[i] << endl;
	}

	return 0;
}
