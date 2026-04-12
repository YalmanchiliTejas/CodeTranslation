#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<ll> s(n);
    for(int i=0;i<n;i++) cin>>s[i];

    auto calc=[&](vector<vector<ll>> &sum){
        for(int i=1;i<n;i++){
            sum[i].push_back(0);
            for(int j=0;j<n;j+=i){
                sum[i].push_back(sum[i].back()+s[j]);
            }
        }
    };
    vector<vector<ll>> sum0(n);
    calc(sum0);
    reverse(s.begin(),s.end());
    vector<vector<ll>> sum1(n);
    calc(sum1);
    reverse(s.begin(),s.end());

    vector<vector<int>> divs(n);
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j+=i){
            divs[j].push_back(i);
        }
    }

    ll res=0;
    auto f0=[&](int X,int t0){
        return sum0[X][t0];
    };
    auto f1=[&](int X,int p){
        return sum1[X][p];
    };
    for(int A=2;A<n-1;A++){
        for(auto X:divs[n-1-A]){
            if(X>=A) continue;
            int t0=(n-1-A)/X;
            int t=A/X;
            int p=(n-1-A)/X+1;
            if(t*X==A && t<=t0) continue;
            res=max(res,f0(X,t0+1)+f1(X,p));
        }
    }
    cout<<res<<endl;
    return 0;
}