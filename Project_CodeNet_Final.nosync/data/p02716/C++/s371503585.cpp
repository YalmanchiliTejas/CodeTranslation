#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;


int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
	ll N;
	cin>>N;

    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
    }
    ll s_min,s_max;
    ll g_min,g_max;
    ll num;
    ll min_sum = -1e15;
    typedef map<ll,ll> mp;
    vector<mp> dp_0(N),dp_1(N);
    dp_0[0][0]=0;
    dp_0[0][1]=min_sum;
    dp_1[0][1]=A[0];
    dp_1[0][0]=min_sum;
    
    for(ll i=1;i<N;i++){
        s_min = max(0ll,N/2-(N-i+1)/2);
        s_max = min(N/2,(i+1)/2);
        g_min = max(0ll,N/2-(N-(i+1)+1)/2);
        g_max = min(N/2,(i+2)/2);
        // cout<<i+1<<"回目"<<"\n";
        // cout<<s_min<<" "<<s_max<<"\n";
        // cout<<g_min<<" "<<g_max<<"\n";
        num = g_min;
        while(num<=g_max){
            // dp_0の更新
            if(s_max>=num){
                dp_0[i][num] = max(dp_0[i-1][num],dp_1[i-1][num]);
                // cout<<0<<i<<" "<<num<<"\n";
                // cout<<dp_0[i][num]<<"\n";
            }else{
                dp_0[i][num] = min_sum;
            }
            
            // dp_1の更新
            if(s_min<=num-1){
                dp_1[i][num] = dp_0[i-1][num-1]+A[i];
                // cout<<1<<i<<" "<<num<<"\n";
                // cout<<dp_1[i][num]<<"\n";
            }else{
                dp_1[i][num] = min_sum;
            }
            ++num;
        }
    }

    ll ans = max(dp_0[N-1][N/2],dp_1[N-1][N/2]);
    cout<<ans<<"\n";
    
	return 0;
}