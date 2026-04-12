//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

ll ray[51] = {};
ll pat[51] = {};

ll burger(int n, ll k){
	//cout << n << " " << k << endl;  
	if(k <= 0) return 0;
	else if(n == 0) return 1;
	else if(k >= ray[n-1] + 2){
		return  pat[n-1] + 1 + burger(n - 1, k - 2 - ray[n-1]);
	}
	else if(k == ray[n-1] + 1){
		return  pat[n-1];
	}
	else{
		return  burger(n-1, k-1);
	}
}

int main() {
	ray[0] = 1;
	REP1(i, 50) ray[i] = ray[i-1] *2 +3;
	pat[0] = 1;
	REP1(i, 50) pat[i] = pat[i-1] *2 +1;
	int ans = 0;
	int tmp;
	int n; ll k;
	cin >> n >> k;
	cout << burger(n, k) << endl;
}