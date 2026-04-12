#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int n;
    cin>>n;
    ll s[n],t[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        t[i]=s[i];
    }
    ll ans1=0;
    sort(s,s+n);
    sort(t,t+n);
    reverse(t,t+n);
    ll a1=s[0],a2=s[0];
    int cnt=0;
    for(int i=0;i<(n-1)/2;i++){
        if(cnt%2==0){
            ans1+=abs(a1-s[n-cnt-1]);
            ans1+=abs(a2-s[n-cnt-2]);
            a1=s[n-cnt-1],a2=s[n-cnt-2];
        }
        else{
            ans1+=abs(a1-s[cnt]);
            ans1+=abs(a2-s[cnt+1]);
            a1=s[cnt],a2=s[cnt+1];
        }
        cnt++;
    }
    if(n%2==0){
        if(n%4==0)n-=2;
        ans1+=max(abs(a1-s[n/2]),abs(a2-s[n/2]));
    }
    
    a1=t[0],a2=t[0];
    ll ans2=0;
    cnt=0;
    for(int i=0;i<(n-1)/2;i++){
        if(cnt%2==0){
            ans2+=abs(a1-t[n-cnt-1]);
            ans2+=abs(a2-t[n-cnt-2]);
            a1=t[n-cnt-1],a2=t[n-cnt-2];
        }
        else{
            ans2+=abs(a1-t[cnt]);
            ans2+=abs(a2-t[cnt+1]);
            a1=t[cnt],a2=t[cnt+1];
        }
        cnt++;
    }
    if(n%2==0){
        if(n%4==0)n-=2;
        ans2+=max(abs(a1-t[n/2]),abs(a2-t[n/2]));
    }
    cout<<max(ans1,ans2)<<endl;
    //cout<<ans1<<ans2<<endl;
    
}
