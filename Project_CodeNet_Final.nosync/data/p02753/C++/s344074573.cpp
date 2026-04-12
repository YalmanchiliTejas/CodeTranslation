#include<bits/stdc++.h>
#define ll long long int
#define ss second
#define ff first
#define pb push_back
#define all(v) v.begin(),v.end()
#define unik(v)  v.erase(unique(v.begin(),v.end()),v.end())
using namespace std;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int sz = 100 + 3, inf = 1e9 + 10;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;cin>>s;
	if(s[0]!=s[1] or s[1]!=s[2])cout<<"Yes\n";
	else puts("No");
	return 0;
}