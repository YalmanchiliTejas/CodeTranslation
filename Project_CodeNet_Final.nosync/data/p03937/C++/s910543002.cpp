#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll h,w,a;
	cin>>h>>w;
	a=0;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			char now;
			cin>>now;
			if(now=='#'){
				a++;
			}
		}
	}
	if(h+w-1==a){
		cout << "Possible";
	}
	else{
		cout << "Impossible";
	}
	// your code goes here
	return 0;
}