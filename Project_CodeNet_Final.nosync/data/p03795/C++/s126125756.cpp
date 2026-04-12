#include<math.h>
#include<map>
#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<array>
#include<tuple>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include <list>
#include<numeric>
//AtCoderC++.cpp

using namespace std;


inline int ceileing(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
int main() {
	int N;cin>>N;
	cout << 800 * N - (N / 15) * 200 << endl;
}