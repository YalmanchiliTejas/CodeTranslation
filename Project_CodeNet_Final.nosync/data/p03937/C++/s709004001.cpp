#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
 
int n, m;
char a[10][10];
 
bool isvalid(int x, int y)
{
	if(x>=0&&x<n&&y>=0&&y<m) return true;
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>a[i][j];
		}
	}
	int x = 0; int y = 0;
	vector<ii> moves;
	moves.pb(mp(0,0));
	for(int i = 1; i <= n + m - 2; i++)
	{
		bool c = 0; bool d = 0;
		if(isvalid(x+1,y)&&a[x+1][y]=='#')
		{
			c=1;
		}	
		if(isvalid(x,y+1)&&a[x][y+1]=='#')
		{
			d=1;
		}
		if(c^d)
		{
			if(c)
			{
				x++;
				moves.pb(mp(x,y));
			}
			else
			{
				y++;
				moves.pb(mp(x,y));
			}
		}
		else
		{
			cout<<"Impossible\n"; return 0;
		}
	}
	for(int i = 0; i < moves.size(); i++)
	{
		a[moves[i].fi][moves[i].se] = '.';
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j]=='#')
			{
				cout<<"Impossible\n"; return 0;
			}
		}
	}
	cout<<"Possible\n";
}