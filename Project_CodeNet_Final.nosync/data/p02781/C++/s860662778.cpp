#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> st;
int k,ans,n,cnt;
int main(void){
    cin>>s>>k;
    n=s.size();
    if(s.size()<k){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>0)st.push_back(i+1);
        if(st.size()>3)cnt+=(s[i]-'0');
    }
    if(k==1){
        ans=(s[0]-'0')+(s.size()-1)*9;
    }
    else if(k==3){
        if(st.size()>=3){
            ans+=((s[st[2]-1]-'0'));
            ans+=(n-st[2])*9;
        }
        if(st.size()>=2){
            ans+=((s[st[1]-1]-'0')-1)*(n-st[1])*9;
            ans+=(n-st[1])*(n-st[1]-1)/2*9*9;
        }
        ans+=((s[st[0]-1]-'0')-1)*(n-st[0])*(n-st[0]-1)/2*9*9;
        ans+=(n-st[0])*(n-st[0]-1)*(n-st[0]-2)/6*9*9*9;
    }
    else{
        if(st.size()>=2){
            ans+=((s[st[1]-1]-'0'));
            ans+=(n-st[1])*9;
        }
        //cout<<ans<<endl;
        ans+=((s[st[0]-1]-'0')-1)*(n-st[0])*9;
        ans+=(n-st[0])*(n-st[0]-1)/2*9*9;
    }
    cout<<ans<<endl;
}
