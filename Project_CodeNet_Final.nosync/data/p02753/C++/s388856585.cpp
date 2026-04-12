#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
*/

bool ok=true;
string s;

int main(void){
	cin>>s;
	if(s[0]=='A' && s[1]=='A' && s[2]=='A')ok=false;
	if(s[0]=='B' && s[1]=='B' && s[2]=='B')ok=false;
	cout<<(ok?"Yes":"No")<<endl;
	return 0;
}