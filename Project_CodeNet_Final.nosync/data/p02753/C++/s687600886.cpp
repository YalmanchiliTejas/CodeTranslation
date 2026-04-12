#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<utility>
#include<functional>
#include<cfenv>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define vint vector<int>
#define vvint vector<vint>
#define P pair<int,int>
#define INT_MAX 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;


int main(void) {
	string n; cin >> n;
	
	if (n[0] == n[1] && n[1] == n[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}
