#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1e9+7;

void U(auto &x,auto y){
    x=(x+y)%mod;
}
ll K(ll x,ll y=mod-2){
    ll t=1;
    for (;y;y>>=1,x=x*x%mod)
        if (y&1) t=t*x%mod;
    return t;
}

struct VAL{
    int v[2][2][2];
}nil, one;

VAL operator + (VAL a,VAL b){
    VAL c=nil;
    for (int la=0;la<=1;++la)
        for (int ra=0;ra<=1;++ra)
            for (int fa=0;fa<=1;++fa)
                for (int lb=0;lb<=1;++lb)
                    for (int rb=0;rb<=1;++rb)
                        for (int fb=0;fb<=1;++fb){
                            U(c.v[la][rb][fa|fb|ra==lb],(ll)a.v[la][ra][fa]*b.v[lb][rb][fb]);
                        }
    return c;
}

int n;

VAL calc(vector<int>vec){
    int mn=*min_element(vec.begin(),vec.end()), sz=vec.size();
    VAL res=nil; int fir=1;
    for (int i=0;i<sz;++i){
        VAL tmp;
        if (vec[i]==mn) tmp=one;
        else {
            vector<int>nex;
            while (i<sz&&vec[i]>mn) nex.push_back(vec[i]-mn+1), ++i;
            --i;
            tmp=calc(nex);
        }
        if (fir) res=tmp, fir=0;
        else res=res+tmp;
    }
    int t=mn-1;
    if (!t) return res;
    VAL re2=nil;
    for (int lb=0;lb<=1;++lb)
        for (int rb=0;rb<=1;++rb)
            for (int fl=0;fl<=1;++fl){
                if (!fl){
                    for (int dif=0;dif<=1;++dif)
                        U(re2.v[lb^dif][rb^dif][fl],res.v[lb][rb][fl]*K(2,t-1));
                }else{
                    int dif=t&1;
                    U(re2.v[lb^dif][rb^dif][fl],res.v[lb][rb][fl]);
                }
            }
    return re2;
}

int main(){
    cin>>n;
    vector<int>vec;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        vec.push_back(x);
    }
    one.v[1][1][0]=one.v[0][0][0]=1;
    VAL res=calc(vec);
    int ans=0;
    for (int lb=0;lb<=1;++lb)
        for (int rb=0;rb<=1;++rb)
            for (int fl=0;fl<=1;++fl)
                U(ans,res.v[lb][rb][fl]);
    cout<<ans<<endl;
}