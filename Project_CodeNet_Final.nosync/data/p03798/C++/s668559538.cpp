//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>
#include <bitset>
#include <time.h>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) a.begin(), a.end()

template<typename T>
void vdeb(vector<T> &da) {
	int size = da.size();
	for (int i = 0;i < size;i++) {
		if (i == size - 1) {
			cout << da[i] << endl;
		}
		else {
			cout << da[i] << ' ';
		}
	}
}
template<typename T>
void vvdeb(vector<T> &da) {
	int size = da.size();
	for (int i = 0;i < size;i++) {
		vdeb(da[i]);
	}
}
int n;
string s;
vector<bool> ju(100100);

bool check(bool a, bool b, vector<bool> &da){
	da[0] = a, da[1] = b;
	rip(i,n,2){
		da[i] = (da[i-1]^da[i-2]^ju[i-1]);
	}
	return ((da[n-1]^da[n-2]^ju[n-1]^da[0])|(da[n-1]^da[0]^ju[0]^da[1]));
}

void out(vector<bool> &da){
	rip(i,n,0){
		if(da[i]) printf("W"); else printf("S");
	}
	cout << endl;
}

vector<vector<bool>> li = {{false, false}, {false, true}, {true, false}, {true, true}};

int main(){
	cin >> n >>s;
	rip(i,n,0) ju[i] = (s[i] == 'x');
	//vdeb(ju);
	vector<bool> da(n);
	rip(i,4,0){
		bool a = li[i][1], b = li[i][0];
		if(!check(a, b,da)){
			out(da);
			return 0;
		}
		//out(da);
	}
	cout << -1 << endl;
	return 0;
}