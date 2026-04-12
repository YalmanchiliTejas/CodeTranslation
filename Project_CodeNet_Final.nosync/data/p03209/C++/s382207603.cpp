#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

ll rec(int n, ll x){
	if(n==0) return 1;
	ll len = (1LL<<(n+1))-3;
	ll pd = (1LL<<n)-1;
	if(x==1)return 0;
	else if(x < len+2) return rec(n-1,x-1);
	else if(x == len+2) return pd+1;
	else if(x < len*2+3) return pd+1 + rec(n-1,x-len-2);
	else  return pd*2+1;
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	cout << rec(n,x) << endl;
	return 0;
}