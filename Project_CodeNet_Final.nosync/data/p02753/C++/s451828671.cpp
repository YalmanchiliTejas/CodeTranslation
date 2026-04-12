#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define all(v)    ((v.begin()),(v.end()))
#define sz(v)     ((int)(v.size()))
#define forv(i, v) for(int i = 0; i < sz(v); ++i)
#define forn(i,n)   for(int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector< vi >    vii;
typedef vector< vd >    vdd;
typedef vector<string>  vs;


int main()
{
	fast;
	string a;
	cin >> a;
	if (a == "AAA" || a == "BBB") cout << "No\n";
	else cout << "Yes\n";

	return 0;
}
