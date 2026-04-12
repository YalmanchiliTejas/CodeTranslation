#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

char a[10][10];
bool b[10][10];
int main() {
	ll h,w;
	cin>>h>>w;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				b[i][j]=true;
			}
		}
	}
	b[0][0]=false;
	b[h-1][w-1]=false;
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			char now=a[i][j];
			if(now=='#'){
				if(a[i+1][j]=='#'&&i+1<h){
					b[i+1][j]=false;
					continue;
				}
				if(a[i][j+1]=='#'&&j+1<w){
					b[i][j+1]=false;
					continue;
				}
			}
		}
	}
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			if(b[i][j]==true){
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	// your code goes here
	return 0;
}