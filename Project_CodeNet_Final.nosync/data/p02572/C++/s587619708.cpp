#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip> 
#define pb push_back
#define mp make_pair
#define fi first 
#define se second
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define per(j, a, b) for (long long j = a; j >= b; j--)
using namespace std;
long long const MOD = 1000000007;
int main(){
	long long n, sum = 0, ans = 0;
	cin >> n;
	vector <long long> v(n);
	rep(i,0,n){
		cin >> v[i];
		sum +=v[i];
	}
	rep(i,0,n-1){
		sum -=v[i];
		ans+= ((sum%MOD)*v[i])%MOD;
		ans%=MOD;
	}
	cout << ans << endl;
}

