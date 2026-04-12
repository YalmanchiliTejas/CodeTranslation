#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
bool cmp(char a, char b){
	return a<b;
}
ll solve(){
	ll x;
	cin>>x;
	if(x>=30) cout<<"Yes";
	else cout<<"No";
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
