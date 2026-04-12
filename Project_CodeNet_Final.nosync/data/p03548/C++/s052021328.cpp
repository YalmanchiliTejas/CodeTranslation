#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int x,y,z;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>x>>y>>z;
	x-=z;
	cout<<x/(y+z);
	re 0;
}