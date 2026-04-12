# pragma GCC optimize("O3")
# include <bits/stdc++.h>
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define rcg(s) cout << s;exit(0)
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define int ll
using namespace std;

int n,x;

int32_t main(){_
    //freopen("input","r",stdin);
	cin >> n;
	int rev = 1;
	deque<int>deq;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		if(rev == 1) deq.push_back(x);
		else deq.push_front(x);
		rev = !rev;
	}
	if(!rev) reverse(deq.begin(),deq.end());
	for(auto it : deq) cout << it << ' ';
}