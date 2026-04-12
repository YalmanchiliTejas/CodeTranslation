#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<bitset>
#include<string>
#include <deque>
#include<queue>
#include <iomanip>
#include<map>
#include <random>
#include<type_traits>
#include<stack>
#include <sstream> 
using namespace std;


#define ll long long int
#define all(v) begin(v), end(v)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
//typedef vector<int> V;
//typedef vector<VV> VVV;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
	vector.erase(vector.begin() + index);
}


int main() {
	int n,max=0,h,y=0;
	cin >>n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (max <= h) {
			max = h;
			y += 1;
		}
	}
	cout << y << endl;
}
