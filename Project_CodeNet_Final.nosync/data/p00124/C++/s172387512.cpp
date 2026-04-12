#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define REP(i,a,n) for(ll i=n;i>a;i--)

int main(void){
    string name[10] = {};
    ll w[10] = {},l[10] = {},d[10] = {},score[10] = {};
    bool is_used[10] = {false};
    bool temp = false;
    
    while(1){
        ll n = 0;
        cin >> n;
        if(!n) break;
        if(temp)cout << endl;
        
        rep(i,0,10){
            is_used[i] = false;
            score[i] = -1;
        }
        
        rep(i,0,n){
            cin >> name[i] >> w[i] >> l[i] >> d[i];
            score[i] = w[i] * 3 + d[i];
        }
        
        
        rep(i,0,101){
            rep(j,0,n){
                if(score[j] == 100 - i) cout << name[j] << "," << score[j] << endl;
            }

        }
        temp = true;
    }
    
}
