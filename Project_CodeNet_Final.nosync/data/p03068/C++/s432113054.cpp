#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
#define ll long long

int main(){
    int n,k;
    cin>>n;
    string s;
    cin>>s;
    cin>>k;

    rep(i,n){
        if(s[i]!=s[k-1]) s[i]='*';
    }
    cout<<s<<endl;
}