#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf 1000000000007;
typedef long long ll;
int main(){
	fast;
	string s; cin>>s;
	if(s[0]==s[1]&&s[1]==s[2])cout<<"No";
	else
		cout<<"Yes";
	return 0;
}