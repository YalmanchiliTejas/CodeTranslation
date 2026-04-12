#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define sol (k+k)
#define sag (k+k+1)
#define orta (bas + (son-bas)/2)
#define coc g[node][i]
#define mod 1000000007
#define inf 1e18
#define N 1000005
#define lim 10000
using namespace std;

typedef long long ll;

string s;
	
int main()
{

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> s;
	if(s[0] == s[1] && s[1] == s[2])
		cout << "No";
	else
		cout << "Yes";
    return 0;
}
