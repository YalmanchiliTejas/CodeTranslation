#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

#define MAX (ll(1e6)+7)
#define MOD (ll(1e9)+7)
#define INF (ll(1e18)+7)

#define elif else if
#define def inline auto
#define for(a,b) for(ll a=0;a<(b);++a)
#define array_size(a) ll(sizeof(a)/sizeof(a[0]))
#define ios_boost cin.tie(0);ios::sync_with_stdio(false)
#define digit(a) to_string(a).length()
#define lcm(a,b) a*b/gcd(a,b)
char N='\n',S=' ';
def gcd(ll a,ll b){ll c;while(a){c=a;a=b%a;b=c;}return b;}

ll check[100+100];
int main(){
	ios_boost;
	ll H,W;
	cin>>H>>W;
	string A[H];
	for(i,H)cin>>A[i];
	for(i,H){
		for(j,W){
			if(A[i][j]=='#')goto rapid;
		}
		check[i]=-1;
		rapid:;
	}
	for(i,W){
		for(j,H){
			if(A[j][i]=='#')goto express;
		}
		check[H+i]=-1;
		express:;
	}
	for(i,H){
		for(j,W){
			if(check[i]!=-1 && check[H+j]!=-1){
				cout<<A[i][j];
			}
		}
		if(check[i]!=-1)cout<<"\n";
	}
}

//for compilation: g++ -o _ _.cpp -std=c++14 (or 17)
//
//for fastening: g++ -O2 -o _ _.cpp -std=c++14 (or 17)
//for fastening: g++ -O3 -mtune=native -march=native -o _ _.cpp -std=c++14 (or 17)
