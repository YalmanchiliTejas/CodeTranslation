#pragma GCC optimize("Ofast")
#pragma GCC optimize("-ffloat-store")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define inf  1e18
#define ps(x,y)   fixed<<setprecision(y)<<x
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    FIO;
    ll n;
    cin>>n;
    if(n>=30)
    cout<<"Yes"<<endl;
    else 
    cout<<"No"<<endl;
return 0;   
}