#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    bool a=false;
    rep(i,s.size()-1){
        if(s[i]=='A'&&s[i+1]=='C')a=true;
    }
    if(a==true)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}