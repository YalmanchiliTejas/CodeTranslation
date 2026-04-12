/** "Ever tried.
         Ever failed.
               No matter.
                   Try Again.
                        Fail again.
                             Fail better.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define bp  __builtin_popcount
#define endl "\n"
#define oo 0x3f3f3f3f3f3f3f3fLL
#define pb push_back
#define loop(i,n) for(int i = 0;i < int(n);i++)
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define setdp memset(dp,-1,sizeof(dp))
#define db(x) cout<<" LOOK "<<(#x)<<" = "<<x <<'\n'
#define NumofDigits(n)   ((long long)log10(n)+1)

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
const  double EPS = 1e-9;
const int MOD = 1e9+7;
/*
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fastpow(ll b, ll p)
{if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};*/
inline void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //File();
    int n;
    cin>>n;
    int arr[105];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        bool ok=true;
        for(int j=0; j<i; j++)
            if(arr[i] < arr[j])
            {
                ok=false;
                break;
            }
        if(ok)
            cnt++;
    }
    cout<<cnt<<endl;
}
