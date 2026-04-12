#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
ll strtoint(string str);
int main(){
	fast;
	ll n,m;
	cin>>n>>m;
	(m==n)?cout<<"Yes\n":cout<<"No\n";
	return 0;
}
ll strtoint(string str){
	ll x=0;
	stringstream ss;
	ss<<str;
	ss>>x;
	return x;
}