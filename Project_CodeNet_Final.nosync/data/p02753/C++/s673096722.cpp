#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define pb push_back
     
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
	string s;
	cin>>s;
	if((s[0]=='A' && s[1]=='A' && s[2]=='A') || (s[0]=='B' && s[1]=='B' && s[2]=='B'))
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}