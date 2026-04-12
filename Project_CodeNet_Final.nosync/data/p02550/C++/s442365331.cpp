#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll> res(m,-1);//余りrが出た最小のインデックスを持つ
    res[x]=0;
    int ind=1;
    vector<ll> sum;
    sum.emplace_back(x);
    ll ans=0;
    ll ps=-1,len=-1;
    int ofs=0;
    while(ind<n) {
        x=x*x;
        x%=m;
        sum.emplace_back(sum.back()+x);
//assert(sum.size()-1==ind);
        if(res[x]==-1)res[x]=ind;
        else {
            if(res[x]!=0) {
                ans+=sum[res[x]-1];
                ofs=res[x];

                len=ind-res[x];
                ps=sum[ind-1]-sum[res[x]-1];
                ans+=ps*((n-ofs)/len);
                int rem=(n-ofs)%len;
                ans+=sum[res[x]+rem-1]-sum[res[x]-1];
            }
            else {
                len=ind;
                ps=sum[ind-1];
                ans+=ps*(n/len);
                int rem=n%len;
                if(rem!=0)ans+=sum[rem-1];
            }
            break;
        }
        ++ind;
    }
    if(ind==n)cout<<sum[n-1]<<endl;
    else cout<<ans<<endl;
    return 0;
}
