#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define fill(a,val)  memset(a,val, sizeof (a))
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(cont) cont.begin(), cont.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max(a,d),max(b,c))
#define MAX   1e9
#define MIN  -1e9
#define PI 3.14159265358979
#define eps 1e-9
typedef map<int,int> mpi;
typedef set<int> seti;
typedef multiset<int> mseti;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, n)    for(long long int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(long long int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(long long int i = a; i >= (n); --i)
#define repn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define trav(a, x) for(auto& a : x)
#define dbg(x) cout << #x << " = " << x << '\n'
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl
#define inp(a,start,len) for(long long int i = start;i < len;i++) cin>>a[i]
struct Interval{ll start,end;};
bool compare(Interval i1, Interval i2) {return (i1.start < i2.start);}

ll vis[100001];

int main(){
	fio;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll T = 1;
	// cin>>T;
	while(T--){
		ll n,x,m;
		cin>>n>>x>>m;
		ll getFirst = -1;
		ll nx = x;
		vis[x] = 1;
		while(getFirst == -1){
			x = (x*x)%m;
			if(vis[x])
				getFirst = x;
			vis[x] = 1;
		}
		ll ans = 0;
		ll used = 0;
		ll cycleLength = 1;
		x = nx;
		while(x!=getFirst){
			ans = (ans+x);
			used++;
			x = (x*x)%m;
		}
		n = n - used;
		x = getFirst;
		ll reached = 0;
		ll prefix[m+1];
		prefix[0] = 0;
		prefix[1] = x;
		while(!reached){
			x = (x*x)%m;
			if(x == getFirst){
				reached = 1;
				break;
			}
			cycleLength++;
			prefix[cycleLength] = (prefix[cycleLength-1] + x);
		}
		ll rot = n/cycleLength;
		ans = ans + rot*prefix[cycleLength];
		n = n%cycleLength;
		ans = ans + prefix[n];
		cout<<ans;
	}
	return 0;
}
