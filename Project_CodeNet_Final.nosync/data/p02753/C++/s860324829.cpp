
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
const ll N = 1000030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    1e9+7;

int main()
{
		ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
string s;
cin>>s;
bool a=false,b=false;
rep(i,0,3)
{
	if(s[i]=='A')
	a=true;
	else
	b=true;
}
if(a&&b)
cout<<"Yes";
else
cout<<"No";

}