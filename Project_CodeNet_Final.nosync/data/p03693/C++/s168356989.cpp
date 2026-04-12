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

signed main(){
	ios_base::sync_with_stdio(0);
	int r,g,b;
	cin>>r>>g>>b;
	int x=r*100+g*10+b;
	cout<<(x%4?"NO":"YES");
	re 0;
}