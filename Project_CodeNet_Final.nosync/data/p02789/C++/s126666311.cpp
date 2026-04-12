#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include <set>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<fstream>
#include<stdio.h>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

#define PI  3.141592
//----------------------------------------


long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}




int main(void)
{
	int n, k;

	cin >> n >> k;

	if (n == k) cout << "Yes" << endl;

	else cout << "No" << endl;


}

