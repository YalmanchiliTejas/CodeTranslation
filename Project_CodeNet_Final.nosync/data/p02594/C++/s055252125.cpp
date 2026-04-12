#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double

#define mod 1000000007
#define EULER 2.7182818284
#define INF 1000000000

#define pb push_back
#define ins insert
#define IT iterator
#define PQ priority_queue
#define    nl           "\n"
#define fi first
#define se second
#define maxe max_element
#define mine min_element
#define er erase
#define lb lower_bound
#define ub upper_bound

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mpi map<int,int>
#define mpl map<ll,ll>
#define umpi unordered_map<int,int>
#define umpl unordered_map<ll,ll>
#define si set<int>
#define sl set<ll>
#define msi multi_set<int>
#define msl multi_set<ll>

#define mem(v,i) memset(v,i,sizeof(v)) 


#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define reprab(i,a,b) for(int i=(a);i>=(b);i--)
#define repll(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)
#define tc int t;cin>>t;while(t--)


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

ll max(ll a,ll b)
{
    if(a>b)return a;return b;
}
ll min(ll a,ll b)
{
    if(a<b)return a;return b;
}

ll mypow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}


int main()
{   
    
    fast
    int t;
    cin>>t;
    if(t>=30)
    cout<<"Yes\n";
    else
    cout<<"No\n";
    
    return 0;
}