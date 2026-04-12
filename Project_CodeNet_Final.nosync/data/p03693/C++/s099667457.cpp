#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <list>
#include <math.h>
#include <map>
using namespace std;
#define REP(i, k, n) for(int i = k;i < n; i++)
#define rep(i, n) REP(i,0,n)
#define ll long long int
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
#define eps 10e-6
#define mod 1000000007
ll a[100001];
int n;
int main(void){
	int a = 100;
	int ans = 0;
	for(int i = 0; i < 3; i++){
		int tmp;
		cin >> tmp;
		ans += (tmp * a);
		a/=10;
	}
	cout << ((ans%4 == 0)?"YES":"NO") << endl;
}
