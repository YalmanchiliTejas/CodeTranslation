/* ****GT_18**** */
//Motivational Source->FUHPD

#include<bits/stdc++.h>
#define	MIN(a,b,c)	min(min(a,b),c)
#define	MAX(a,b,c)	max(max(a,b),c)
#define ll          long long
#define itr         vector<ll int>::iterator
#define pb          push_back
#define mp          make_pair
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
using namespace std;
struct disset
{
	int data,rank,parent;
};
int find_set(struct disset *sets,int node)
{
	if(sets[node].parent!=node)
	sets[node].parent=find_set(sets,sets[node].parent);
	return sets[node].parent;
}
void merge_set(struct disset *sets,int x,int y)
{
	int xparent=find_set(sets,x);
	int yparent=find_set(sets,y);

	if(sets[xparent].rank>sets[yparent].rank)
	sets[yparent].parent=xparent;
	else if(sets[xparent].rank<sets[yparent].rank)
	sets[xparent].parent=yparent;
	else
	{
		sets[xparent].parent=yparent;
		sets[yparent].rank++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		int n;
		cin>>n;
		vector<pii> x(n),y(n);
		vector<pair<ll,pii> > a;
		rep(i,0,n)
		{
			cin>>x[i].F>>y[i].F;
			x[i].S=i;
			y[i].S=i;
		}
		sort(all(x));
		sort(all(y));
		rep(i,1,n)
		{
			a.pb({x[i].F-x[i-1].F,{x[i].S,x[i-1].S}});
			a.pb({y[i].F-y[i-1].F,{y[i].S,y[i-1].S}});
		}
		sort(all(a));
		disset sets[n];
		rep(i,0,n)
		{
			sets[i].data=i;
			sets[i].parent=i;
			sets[i].rank=0;
		}
		ll ans=0;
		rep(i,0,sz(a))
		{
			if(find_set(sets,a[i].S.F)!=find_set(sets,a[i].S.S))
			{
				ans+=a[i].F;
				merge_set(sets,a[i].S.F,a[i].S.S);
			}
		}
		cout<<ans;
	}
	return 0;
}
