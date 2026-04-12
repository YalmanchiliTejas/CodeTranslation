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

bool visited[111111];
int p[100001];
int q[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x;
	cin>>n>>x;
	vi perm(n);
	for(int i = 0; i < n; i++) perm[i] = i;
	for(int i = 0; i < x; i++)
	{
		cin>>p[i]>>q[i];
		p[i]--; q[i]--;
	}
	vi P = perm;
	vi inv = perm;
	for(int i = 0; i < x; i++)
	{
		swap(inv[P[p[i]]], inv[P[q[i]]]);
		swap(P[p[i]],P[q[i]]);
	}
	visited[inv[0]]=1;
	visited[inv[1]]=1;
	visited[inv[0]+1]=1;
	if(inv[0]>0) visited[inv[0]-1]=1;
	vi P2 = perm;
	vi inv2 = perm;
	for(int i = 0; i < x; i++)
	{
		swap(inv2[P2[p[i]]], inv2[P2[q[i]]]);
		swap(P2[p[i]],P2[q[i]]);
		swap(inv[p[i]], inv[q[i]]);
		swap(P[p[i]],P[q[i]]);
		int pos = inv2[0];
		visited[inv[pos+1]] = 1;
		if(pos>0) visited[inv[pos-1]] = 1;
	}
	//cerr<<inv[0]<<'\n';
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(visited[i]) ans++;
	}
	cout<<ans<<'\n';
}
