#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll p[55],t[55];

ll Calc(ll lv, ll maisuu)
{
    
    if(lv==0)
    {
        return 1LL;
    }
    if(maisuu<2)
    {
        return 0;
    }
    else if(maisuu<=t[lv-1]+1)
    {
        return Calc(lv-1, maisuu-1);
    }
    else if(maisuu <=t[lv-1]+2)
    {
        return p[lv-1]+1;
    }
    else
    {
        return p[lv-1]+ 1 + Calc(lv-1,maisuu-t[lv-1]-2);
    }
    
    return 0;
}

int main(){
    ll n,x,ans=0;
    cin>>n>>x;
    p[0]=1LL;
    t[0]=1LL;
    for(int i = 0; i < 52; i++)
    {
        p[i+1]=p[i]*2LL+1LL;
        t[i+1]=t[i]*2LL+3LL;
    }
    
    ans = Calc(n,x);

    cout<<ans<<endl;
    return 0;
}