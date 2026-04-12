#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include<math.h>
using namespace std;
//#define int long long
#define m_p make_pair
#define mod 1000000007
#define rep(i,n)  for(int i=0; i<(int) (n); i++)
#define all(v)  v.begin(),v.end()
#define vecin(v) for(int i=0; i<(int)v.size(); i++)cin>>vec[i];
using namespace std;

int jousu(int, int);
int jousu(int x00, int y00) {
	int z00 = 1;
	for (int i = 0; i < y00; i++) {
		z00 *= x00;
	}
	return z00;
}
int kurai(int x00, int y00) {
	int z00 = (x00 % jousu(10, y00)) / jousu(10, y00 - 1);
	return z00;
}
int keta(int x00) {
	int z00 = x00;
	int w00 = 0;
	while (z00 != 0) {
		z00 /= 10;
		w00++;
	}
	return w00;
}



int main() {
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB") {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}
