#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<deque>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

int n;
string s;

ll gcl(ll x,ll y){
    if(x<y) swap(x,y);
    while(y>0){
        ll t=x%y;
        x=y;
        y=t;
    }
    return x;
}

ll fac(int n){
    if(n==0||n==1) return 1;
    return n*fac(n-1);
}

int main(){
    cin>>n;
    vector<vector<int> > S(n,vector<int>(26,0));
    rep(i,0,n){
        cin>>s;
        int m=s.size();
        rep(j,0,m) S[i][(int)(s[j]-'a')]++;
    }
    
    string ans;
    rep(i,0,26){
        int mina=51;
        rep(j,0,n){
            mina=min(mina,S[j][i]);
        }
        rep(j,0,mina){
            ans+=(char)(i+'a');
        }
    }
    cout<<ans<<endl;    
}