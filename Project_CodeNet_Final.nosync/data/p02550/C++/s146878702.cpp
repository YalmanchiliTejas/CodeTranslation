#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl=vector<ll>;

int main() {
    ll N,X,M; cin>>N>>X>>M;
    set<ll> appear;
    vl seq;
    ll before_loop=0;
    ll loop_len=0;
    appear.insert(X);
    seq.push_back(X);
    ll next=X*X%M;
    while(!appear.count(next)){
        appear.insert(next);
        seq.push_back(next);
        next=next*next%M;
    }
    ll ans=0;
    for (int i = 0; i < seq.size(); i++){
        if(seq[i]==next)break;
        else {
            ans+=seq[i];
            before_loop++;
        }
    }
    loop_len=seq.size()-before_loop;
    vl sum(loop_len);
    sum[0]=seq[before_loop];
    for (int i =1; i < loop_len; i++){
        sum[i]=sum[i-1]+seq[before_loop+i];
    }
    N-=before_loop;
    if(loop_len!=0){
        ans+=N/loop_len*sum[loop_len-1];
        if(N%loop_len!=0)ans+=sum[N%loop_len-1];
    }
    cout<<ans<<endl;
}