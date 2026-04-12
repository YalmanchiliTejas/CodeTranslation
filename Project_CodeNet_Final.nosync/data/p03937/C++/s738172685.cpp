#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll h,w,ans=0;
	cin>>h>>w;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			char x;
			cin>>x;
			if(x=='#'){
				ans++;
			}
		}
	}
	cout << (ans==h+w-1? "Possible":"Impossible");
	// your code goes here
	return 0;
}