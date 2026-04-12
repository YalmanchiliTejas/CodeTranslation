#include <bits/stdc++.h>

using namespace std;

//#define cin fi
//#define cout fo

//ifstream fi ("HP.INP");
//ofstream fo ("HP.INP");

int m = 1e9+7;

int main(){
//	freopen("test.txt" , "r" , stdin);
//	ios_base:: sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	unsigned long long  n;
	cin >> n;
	unsigned long long  a, pre = 0, res = 0;
	cin >> a;
	pre += a;
	for (unsigned long long  i = 2 ; i <= n ; i++){
		cin >> a ;
		res +=(a % m )* pre;
		res %= m;
	 	pre += a;
	 	pre %= m;
	}

	cout << res % m;
	return 0;
}