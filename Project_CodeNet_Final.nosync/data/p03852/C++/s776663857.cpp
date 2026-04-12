#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int MOD=1000000007;
signed main(){
    string c;cin>>c;
    string s={"aiueo"};
    bool flag=false;
    rep(i,5){
        if(c[0]==s[i])flag=true;
    }
    if(flag)cout<<"vowel";
    else cout<<"consonant";
    cout<<endl;
    return 0;
}