#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> plli;
typedef vector< vi > vvi ;
typedef vector< vlli > vvlli  ;
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define flli(i,a,b) for(long long int i=a;i<=b;i++)
#define bi(i,a,b) for(int i=a;i>=b;i--)
#define blli(i,a,b) for(long long int i=a;i>=b;i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pi 2*acos(0.0)
#define pb push_back
#define tr(v,it) for(decltype(v.begin()) it=v.begin();it!=v.end();it++)
#define present(v,num) (v.find(num)!=v.end())
#define cpresent(v,num) (find(v.begin(),v.end(),num)!=v.end())
#define pq priority_queue
#define mp make_pair
const int inf=INT_MAX;
const lli INF =LLONG_MAX;
const lli mod = 1e9+7;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    lli n,x,m;cin>>n>>x>>m;
    if(x==0)
    {
    	cout<<0;
    	return 0;
    }
    set<lli> allpos;
    vlli patt;
    lli var=x;
    allpos.insert(var);
    patt.pb(var);
    lli repnum;
    while(1)
    {
    	var=(var*var)%m;
    	if(present(allpos,var))
    	{
    		repnum=var;
    		break;
    	}
    	else
    	{
    		allpos.insert(var);
    		patt.pb(var);
    	}
    }
    lli ans=0;
    lli szpatt=sz(patt);
    lli ind=0;
    while(n!=0 && patt[ind]!=repnum)
    {
    	ans+=patt[ind];
    	n--;
    	ind++;
    }
    vlli arr;
    lli sumarr=0;
    flli(i,ind,szpatt-1)
    {
    	arr.pb(patt[i]);
    	sumarr+=patt[i];
    }
    lli szarr=sz(arr);
    lli repi=n/szarr;
    ans+=repi*sumarr;
    repi=n%szarr;
    flli(i,0,repi-1)
    {
    	ans+=arr[i];
    }
    cout<<ans<<endl;
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}