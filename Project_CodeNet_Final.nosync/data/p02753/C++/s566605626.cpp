#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FOR(i) for(cin>>i;i>0;i--)
#define elif else if
#define pb push_back
#define ll long long
#define mp make_pair
#define all(x) x.begin(),x.end()
#define re(x) {cout<<x<<endl;return 0;}
//#define x first
//#define y second

using namespace std;
string s;
int main()
{
	cin>>s;
	if(s[1]!=s[0]||s[1]!=s[2]||s[2]!=s[0]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;}