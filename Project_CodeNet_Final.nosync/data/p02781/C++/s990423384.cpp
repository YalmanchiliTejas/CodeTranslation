#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string s;cin>>s;
    int k; cin>>k;
    int l=s.size();
    
    ll ans = 1;
    rep(i,k)ans *= 9*(l-1-i);
    rep(i,k)ans /= i+1;
    
    string t(l, '0');
    
    //1~l-1桁目からk-1個選ぶ->1~9を当てはめる
    if(k==1){
        for(int i=1; i<10; i++){
            t[0] = (char)i+'0';
            if(t<=s)ans++;
            t[0] = '0';
        }
        cout << ans << endl;
    }else if(k==2){
        for(int i=1; i<10; i++){
            t[0] = (char)i+'0';
            for(int j=1; j<l; j++){
                for(int dj=1; dj<10; dj++){
                    t[j] = (char)dj+'0';
                    if(t<=s)ans++;
                    t[j] = '0';
                }
            }
            t[0] = '0';
        }
        cout << ans << endl;
    }else{
        for(int i=1; i<10; i++){
            t[0] = (char)i+'0';
            for(int j=1; j<l; j++){
                for(int dj=1; dj<10; dj++){
                    t[j] = (char)dj+'0';
                    for(int q=j+1; q<l; q++){
                        for(int dq=1; dq<10; dq++){
                            t[q] = (char)dq+'0';
                            if(t<=s)ans++;
                            t[q] = '0';
                        }
                    }
                    t[j] = '0';
                }
            }
            t[0] = '0';
        }
        cout << ans << endl;
    }
    
    return 0;
}