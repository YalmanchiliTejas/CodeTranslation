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

int n,a[1 << 21];

int32_t main(){_
    //freopen("input","r",stdin);
    cin >> n;
    bool rev = 0;
    deque<int>dq;
    for(int i = 1;i <= n;i++)
    {
		cin >> a[i];
		if(!rev) dq.push_back(a[i]);
		else dq.push_front(a[i]);
		rev = !rev;
	}
	if(rev) reverse(dq.begin(),dq.end());
	for(auto it : dq) cout << it << ' ';
	return 0;
}
