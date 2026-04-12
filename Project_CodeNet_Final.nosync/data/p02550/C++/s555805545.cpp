#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main(){
    ll N;cin>>N;
    ll X,M;cin>>X>>M;
    vector<ll>ans;
    set<ll>ANS;
    ll sum=X;
    ans.push_back(X);
    ANS.insert(X);
    bool flag=false;
    for(ll i=1;i<N;i++){
        ll Z=ans[ans.size()-1];
        ll T=(Z*Z)%M;
        ans.push_back(T);
        if(ANS.count(T)){
            flag=true;
            break;
        }
        ANS.insert(T);
        sum+=T;
    }
    if(flag==true){
        ll TT=ans[ans.size()-1];
        ll subsum=0;
        ll C=0;
        rep(i,ans.size()){
            if(ans[i]==TT){
                C=i;
                break;
            }
        }
        ll cntcnt=0;
        for(int i=C;i<ans.size()-1;i++){
            subsum+=ans[i];
            cntcnt++;
        }
        sum+=subsum*((N+1-ans.size())/cntcnt);
        for(int i=C;i<C+(N+1-ans.size())%cntcnt;i++){
            sum+=ans[i];
        }
    }
    cout<<sum<<endl;
}