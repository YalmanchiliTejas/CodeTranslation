#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222];
int n;

bool is_sorted()
{
	for(int i=0;i+1<n;i++)
	{
		if(a[i]>a[i+1]) return false;
	}
	return true;
}

vi moves;

void cyc()
{
	for(int i=1;i<n;i++) swap(a[i],a[i-1]); 
	moves.pb(1);
}

void swp()
{
	swap(a[0],a[n-1]); moves.pb(n-1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	while(!is_sorted())
	{
		vi swapid;
		for(int i=n-2;i>=0;i--)
		{
			if(!swapid.empty()&&swapid.back()==i+1) continue;
			if(a[i]>a[i+1]) swapid.pb(i);
		}
		for(int i=0;i<n;i++)
		{
			cyc();
			if(!swapid.empty()&&swapid.back()==i) {swp();swapid.pop_back();}
		}
	}
	cout<<moves.size()<<'\n';
	for(int v:moves) cout<<v<<'\n';
}
