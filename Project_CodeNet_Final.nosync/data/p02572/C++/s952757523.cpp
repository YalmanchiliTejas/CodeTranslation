/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,n) for(int i=0;i<n;i++)
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define int long long int
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > pii;
#define mp make_pair
#define sz(a) int((a).size())
#define pb push_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define so(v) sort(all(v))
#define sod(v) sort(allr(v))
#define mfind(c, element) (c.find(element) != c.end())
#define gfind(c, element) (find(all(c),element) != c.end())
#define gfindindex(c, element) (find(all(c),element)-c.begin())
#define vp(x) cout << #x << " --> " << x << endl;
#define cp1(v) cout << #v << "--->" << endl; for (auto it : v)  cout << it << " "; cout << endl;
#define cpp1(v) cout << #v << "-->" << endl; for(auto it:v){cout << it.fi << " " << it.se << endl;}
#define ccp1(v) cout << #v << "--->" << endl;for (auto it:v){for(auto it1 : it){cout << it1 << " ";}cout<< endl;}
#define bsnp np3(low,high,mid);
#define hmm1 high=mid-1;
#define lmp1 low=mid+1;
#define hmp1 high=mid+1;
#define lmm1 low=mid-1;
#define fi first
#define se second
#define endl "\n"
#define np1(x) cout<<#x<<"="<<x<<'\n'
#define np2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define np3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
// upper_bound(all(a),k,greater<int>()) gives first no smaller(not greater) than k
 
struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};//comparison used for sorting set<pair<i,i>,cmp>
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
//increasing ordr basedd on 2nd
};
const int mod=1e9 +7;
main()
{
IOS;
int n;cin>>n;
vi a(n);
int s=0,ans=0;
vi pref(n+1,0);
loop(i,n)
{cin>>a[i];pref[i+1]=pref[i]+a[i];}
loop(i,n)
{   
    int s=pref[n]-pref[i];
    int x=((   (s%mod)-(a[i]%mod) + mod )%mod )*(a[i]%mod);
    x=(x+mod)%mod;
    ans=(ans+x)%mod;
}
 
cout<<ans<<endl;
 
return 0;
}