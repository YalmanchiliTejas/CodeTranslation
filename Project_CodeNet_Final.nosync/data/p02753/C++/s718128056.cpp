#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("http://in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int main()
{
	
string s;
cin>>s;
ll a=0,b=0;
for(ll i=0;i<s.length();i++)
{
	if(s[i]=='A')a++;
	else b++;
}
if(a>0 && b>0){cout<<"Yes";return 0;}
else 
cout<<"No";
}