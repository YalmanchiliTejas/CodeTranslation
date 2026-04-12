#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    char c=s[k-1];
    for(int i=0;i<n;i++){
        if(s[i]==c){
            cout<<s[i];
        }
        else{
            cout<<"*";
        }
    }
}