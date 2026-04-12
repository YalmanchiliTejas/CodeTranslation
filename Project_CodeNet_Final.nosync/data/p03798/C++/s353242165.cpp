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

char z[2] = {'S','W'};
int a[100001];
int b[100001];
int n;
void out()
{
	for(int i =0;i<n;i++)
	{
		cout<<z[b[i]];
	}
	cout<<'\n';
}

void no()
{
	cout<<-1<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	 cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o') a[i]=0;
		else a[i]=1;
	}
	if(n==3)
	{
		if(a[0]==a[1]&&a[1]==a[2])
		{
			b[0]=a[0];
			b[1]=b[2]=0;
			out();
		}
		else
		{
			no();
		}
		return 0;
	}
	for(int i = 0; i < (1<<3); i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i&(1<<j)) b[j]=0;
			else b[j]=1;
		}
		for(int j = 0; j < n - 3; j++)
		{
			b[j+3] = (b[j]^(a[j+1]^a[j+2]));
		}
		bool pos=1;
		for(int j = 0; j < n; j++)
		{
			int l = b[(j-1+n)%n];
			int r = b[(j+1)%n];
			int cur = b[j];
			if(((l^r)^cur) != a[j])
			{
				pos=false;
				break;
			}
		}
		if(pos)
		{
			out();
			return 0;
		}
	}
	no();
}
