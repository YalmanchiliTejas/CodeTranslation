#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a[200005];
int main(){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll n=s.length();
    if(k==1){
        cout<<(s[0]-'0')+(n-1)*9<<endl;
    }
    if(k==2){
        ll num=n-k;
        num=(num*(num+1))/2;
        num*=(ll)81;
        ll pos=1;
        while(pos<n&&s[pos]=='0') pos++;
        if(pos!=n){
            num+=(ll)(s[pos]-'0');
            num+=(n-pos-1)*(ll)9;
        }
        for(ll i=1;i<(ll)(s[0]-'0');i++){
            num+=(n-1)*(ll)9;
        }
        cout<<num<<endl;
    }
    if(k==3){
        ll num=0;
        for(ll i=2;i<n-1;i++){
            num+=(i*(i-1))/2;
        }
        num*=(ll)729;
        ll cnt=0;
        for(ll i=1;i<n;i++){
            if(cnt==2) break;
            if(s[i]!='0'){
                cnt++;
                if(cnt==1){
                    num+=((n-i-1)*(n-i-2))/2*81;
                    num+=((s[i]-'0')-1)*(n-i-1)*9;
                }
                if(cnt==2){
                    num+=s[i]-'0'+(n-i-1)*9;
                }
            }
        }
        for(ll i=1;i<(ll)(s[0]-'0');i++){
            num+=((n-1)*(n-2))/2*(ll)81;
        }
        cout<<num<<endl;
    }
}