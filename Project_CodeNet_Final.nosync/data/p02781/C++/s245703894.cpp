#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

ll ctoll(char a){
    return (ll)a-'0';
}

ll calcC(ll a,ll b){
    ll r = 1;
    if(a< b){
        return 0;
    }
    rep(i,b){
        r*=(a-i);
    }
    rep(i,b){
        r/=(i+1);
    }
    return r;
}


int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
	string S;
	cin>>S;
    ll K;
    cin>>K;
	ll l = S.length();
    if(l<K){
        cout<<0<<"\n";
        return 0;
    }
    ll pow9[4] = {1,9,9*9,9*9*9};
    ll ans = 0;
    
    if(l>K){
        ans += calcC(l-1,K)*pow9[K];
    }
    ll max_n = ctoll(S[0]);
    if(K==1){
        ans += max_n;
    }else{
        int second_ind = 1;
        while(S[second_ind]=='0'){
            ++second_ind;
            if(second_ind==l){
                second_ind = l-1;
                break;
            }
        }
        ll second_n = ctoll(S[second_ind]);
        if(K==2){
            ans += (max_n-1)*(l-1)*9+second_n;
            if(second_n!=0){
                ans+=(l-1-second_ind)*9;
            }
        }else{
            ll third_ind = second_ind+1;
            if(third_ind>=l){
                third_ind = l-1;
            }
            while(S[third_ind]=='0'){
                ++third_ind;
                if(third_ind==l){
                    third_ind = l-1;
                    break;
                }
            }
            ll third_n = ctoll(S[third_ind]);
            ans +=(max_n-1)*calcC(l-1,2)*pow9[2];
            if(second_n>0){
                ans += (second_n-1)*(l-1-second_ind)*9;
                ans += calcC(l-1-second_ind,2)*pow9[2];
                if(third_n>0){
                    ans += third_n + (l-1-third_ind)*9;
                }
            }
        }
    }
    cout<<ans<<"\n";
	
	return 0;
}