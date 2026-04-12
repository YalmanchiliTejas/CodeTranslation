# pragma GCC optimize("O3")
# include <bits/stdc++.h>
# define maxn 100005
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define sz(x) (int)((x).size())
//# define int ll
using namespace std;

int32_t main(){_
    //freopen("input","r",stdin);
	int r,g,b;
	cin >> r >>  g >> b;
	int x = g*10 + b;
	if(x % 4 == 0) rc("YES");
	rc("NO");
}