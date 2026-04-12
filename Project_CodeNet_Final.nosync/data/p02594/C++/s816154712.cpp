#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define forn(i,n) for(int i=0;i<n;i++)
#define free(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%lld", &n)
#define sff(a,b) scanf("%lld %lld", &a, &b)
#define sfff(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define pfn(n) printf("%lld\n", n)
#define pfs(n) printf("%lld ", n)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define f find
#define ub upper_bound
#define lb lower_bound
#define ld long double
#define in insert
#define bs binary_search
#define le length()
const ll max_i=1e16+7;
#define np(s) next_permutation(s.begin(),s.end())
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
//it gives the lexicographically smallest string//

void solve()
{
	int t=1;
	//cin>>t;
	while(t--)
    {
       int x;
       cin>>x;
       if(x>=30) cout<<"Yes";
       else cout<<"No";
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r",stdin);
	freopen("output1.txt","w",stdout);
	#endif
	solve();
	return 0;
}