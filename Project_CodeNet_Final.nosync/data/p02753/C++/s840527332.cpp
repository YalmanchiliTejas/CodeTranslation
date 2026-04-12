//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long



using namespace std;

void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
 	
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
 	
 	string a;

 	cin>>a;
 	set<char>s;
 	for(auto c : a)s.insert(c);

 	if(sz(s)>1)cout<<"Yes\n";
 	else	cout<<"No\n";
 	
}		
