#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

bool compare1(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

bool compare2(pair<ll,ll> a,pair<ll,ll> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main(){
    
    int N;cin>>N;
    
    if(N==1) cout<<0<<endl;
    else{
        
        vector<pair<ll,ll>> S(N);
        for(int i=0;i<N;i++){
            ll a,b;cin>>a>>b;
            if(a>b) swap(a,b);
            S[i]=make_pair(a,b);
        }
        
        sort(all(S),compare1);
        ll a=S[0].first,b=S[N-1].first;
        
        sort(all(S),compare2);
        ll c=S[0].second,d=S[N-1].second;
        
        ll ans=(b-a)*(d-c);
        
        sort(S.begin(),S.end()-1,compare1);
        
        swap(S[N-1].first,S[N-1].second);
        
        /*for(int i=0;i<N;i++){
            cout<<S[i].first<<" "<<S[i].second<<endl;
        }*/
        
        ll x=S[1].first,y=S[N-2].first,maxi=max({S[0].second,S[N-1].second,y}),mini=min({S[0].second,S[N-1].second});
        ans=min(ans,(d-a)*(maxi-min(mini,x)));
        
        for(int i=1;i<N-1;i++){
            maxi=max(maxi,S[i].second);
            mini=min(mini,S[i].second);
            ans=min(ans,(d-a)*(maxi-min(mini,S[i+1].first)));
        }
        
        cout<<ans<<endl;
        
        
    }
    
}
