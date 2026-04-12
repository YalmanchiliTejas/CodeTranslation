#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll k,ans=0;
    cin >> k;
    
    ll nagasa=s.length();
    
    
    if(k==1){
        ll x=s[0]-'0';
        ans+=x;
        ans+=(nagasa-1)*9;
    }
    
    if(k==2){
        ll now=nagasa;
        for(ll i=1;i<nagasa;i++){
            if(s[i]!='0'){
                now=i;
                break;
            } 
        }
        for(ll i=now;i<nagasa;i++){
            if(i==now) ans+=s[i]-'0';
            else ans+=9;
        }
        ll x=s[0]-'0';
        ans+=(x-1)*(nagasa-1)*9;
        ans+=(nagasa-1)*(nagasa-2)*81/2;
    }
    
    if(k==3){
        ll now=nagasa;
        ll now2=-1;
        for(ll i=1;i<nagasa;i++){
            if(s[i]!='0'){
                now=i;
                break;
            }
        }
        for(ll i=now+1;i<nagasa;i++){
            if(s[i]!='0'){
                now2=i;
                break;
            }
        }
        if(now2!=-1){
        for(ll i=now2;i<nagasa;i++){
            if(i==now2) ans+=s[i]-'0';
            else ans+=9;
        }
        }
        //cout << ans << endl;
        ans+=81*(nagasa-now)*(nagasa-now-1)/2;
        //cout << ans << endl;
        ll y=s[now]-'0';
        ans-=(10-y)*9*(nagasa-now-1);
        //cout << ans << endl;
        
        ll x=s[0]-'0';
        
        ans+=(x-1)*(nagasa-1)*(nagasa-2)*81/2;
        //cout << ans << endl;
        ans+=9*9*9*(nagasa-1)*(nagasa-2)*(nagasa-3)/6;
    }

    cout << ans << endl;


    return 0;
}







