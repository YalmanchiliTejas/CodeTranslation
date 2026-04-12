#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using V = vector<ll>;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()

int main(){
    string s; cin>>s;
    int a=0,b=0;
    rep(i,0,3){
        if(s[i]=='A')a=1;
        if(s[i]=='B')b=1;
    }
    if(a==1&&b==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}