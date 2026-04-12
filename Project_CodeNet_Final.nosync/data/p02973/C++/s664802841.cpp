#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    int N;
    cin>>N;
    vector<int> A(N),ans(0);
    rep(i,N){
        cin>>A.at(i);
    }
    rep(i,N){
        if(i==0){ans.pb(A.at(i));}
        else{
            int l=-1,r=sz(ans);
            while(r-l>1){
                int m=(r+l)/2;
                if(ans.at(m)>=A.at(i))l=m;
                else{r=m;}
            }
            if(r==sz(ans)){ans.pb(A.at(i));}
            else{ans.at(r)=A.at(i);}
        }
    }
    cout<<sz(ans)<<endl;
}