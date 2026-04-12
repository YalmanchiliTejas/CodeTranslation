/**
 * author  : UshanGhosh
 * created : 2020-08-31 19:45:20
**/ 

#include<bits/stdc++.h>
using namespace std;

#define    ll      long long
#define    pii     pair<int,int>
#define    vii     vector<int>
#define    vcc     vector<char>
#define    pll     pair<long long, long long>
#define    mem     memset
#define    sof     sizeof
#define    co1     __builtin_popcountll
#define    PB      push_back
#define    UB      upper_bound
#define    LB      lower_bound
#define    MP      make_pair
#define    TS      to_string
#define    F       first
#define    S       second
#define    pi      acos(-1)
#define    mod     1000000007
#define    inf     1e18
#define    endl    '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        long long a,b,c,d,e,f,i,j,k,m,n,o,x,y;
        cin>>n;
        ll ar[n];
        for(i=0;i<n;i++) cin>>ar[i];
        ll sum[n];
        for(i=0;i<n;i++){
            if(i==0) sum[i]=ar[i];
            else sum[i]=sum[i-1]+ar[i];
        }
        ll ans = 0;
        for(i=0;i<n;i++){
            ans=(ans+ar[i]*((sum[n-1]-sum[i])%mod))%mod;
        }
        cout<<ans<<"\n";
    }
}