#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int a,b,c;
	cin >> a >> b >> c;
	int ans = 0;
	ans = 100*a + 10*b + c;
	if(ans %4 )
		cout << "NO\n";
	else cout << "YES\n";	
	return 0;
}