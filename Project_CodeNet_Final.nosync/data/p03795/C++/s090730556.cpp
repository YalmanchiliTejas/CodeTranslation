#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
//#include <stdio.h>
//#include <stack>
//#include <queue>
#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>
//#include <fstream>
//#include <list>
//#include <iomanip>
#include <stdlib.h>
#include <cctype>

using namespace std;

#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define ssort(z) sort(z.begin(),z.end())
#define rsort(z) sort(z.rbegin(),z.rend())
#define eerase(z) z.erase(unique(z.begin(),z.end()),z.end())
#define ccnt(z,w) count(z.begin(),z.end(),w)


void printVec(std::vector<int> & vec) {
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void printVec1(std::vector<string>& vec) {
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
void printVec2(std::vector<Int>& vec) {
	std::cout << "";
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

Int gcd(Int a, Int b) {
	return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
	return a / gcd(a, b) *b;
	//a*bは64bit integer overflow
}

bool comp(const string a, const string b) {
	return a.length() < b.length();
}

bool integer(double num) {
	return floor(num) == num;
}

string gen(int num) {
	string str = "";
	for (int i = 0; i < num; i++) str += ".";
	return str;
}
Int fact(int num) {
	if (num == 0) return 1;
	else return num * fact(num - 1);
}


int main() {
	int a, b, c; cin >> a ;
	//string s,t; cin >> s>>t;
	cout << a * 800 - 200 * (a / 15);

	cout << endl;
	return 0;
}