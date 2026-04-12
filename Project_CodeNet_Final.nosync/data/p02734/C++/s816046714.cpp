#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
const ll MOD = 998244353;
int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	ll N,S;
    cin>>N>>S;
    vector<ll> A(N);

    rep(i,N){
        cin>>A[i];
    }

    vector<unordered_map<ll,ll>> mp_v(N);
    ll ans=0;
    rep(i,N){
        if(i==0){
            mp_v[0][0]=1;
            if(A[i]<=S){
                ++mp_v[0][A[i]]=1;
            }
        }else{
            for(auto v :mp_v[i-1]){
                if(v.first==0){
                    mp_v[i][v.first]+=v.second;
                    if(v.first+A[i]<S){
                        mp_v[i][v.first+A[i]]+=v.second;
                        mp_v[i][v.first+A[i]]+=i;
                    }
                    if(v.first+A[i]==S){
                        ans += (i+1)*(N-i);
                        ans = ans%MOD;
                    }
                }else{
                    mp_v[i][v.first]+=v.second;
                    if(v.first+A[i]<S){
                        mp_v[i][v.first+A[i]]+=v.second;
                        mp_v[i][v.first+A[i]]%=MOD;
                    }
                    if(v.first+A[i]==S){
                        ans += (v.second*(N-i))%MOD;
                        ans%=MOD;
                    }
                }
            }    
        }
        if(mp_v[i].find(S)!= mp_v[i].end()){
            ans += mp_v[i][S]*(N-i);
        }
        
    }
    
	cout<<ans<<"\n";
	return 0;
}