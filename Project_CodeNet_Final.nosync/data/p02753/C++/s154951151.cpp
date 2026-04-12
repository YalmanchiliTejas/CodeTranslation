#include<bits/stdc++.h>
#define sonic ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define fi first
#define se second
#define pb push_back
using namespace std;
int main(){sonic
	int T=1;
//	cin>>T;
	while(T--){
		string s;
		cin>>s;
		if(s[0]==s[1]&&s[1]==s[2])cout<<"No\n";
		else cout<<"Yes\n";
	}
}
