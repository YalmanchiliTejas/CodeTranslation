/**
 * author  : UshanGhosh
 * created : 2020-09-19 19:20:21
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
#define    mod     (int)1e9+7
#define    inf     (long long)1e18
#define    endl    '\n'

ll ar[100000], pos[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,d,e,f,i,j,k,m,n,o,x,y;
    cin>>a>>b>>c;
    ll ans = b%c;
    ll pans = b%c;
    memset(ar,-1,sizeof(ar));
    ar[pans] = 0;
    pos[pans] = 1;
    ll rem = 0;
    for(i=2;i<=a;i++){
        pans = (pans*pans)%c;
        if(ar[pans]!=-1){
            ll lans = ans - ar[pans];
            ll cnt = i-pos[pans];
            rem = (a-i+1)%cnt;
            d = pans;
            ans += ((a-i+1)/cnt)*lans;
            break;
        }
        ar[pans] = ans;
        pos[pans] = i;
        ans+=pans;
        if(pans==0) break;
    }
    for(i=0;i<rem;i++){
        if(i==0) ans+=pans;
        else{
            pans*=pans;
            pans%=c;
            ans+=pans;
        }
    }
    cout<<ans<<"\n";
}