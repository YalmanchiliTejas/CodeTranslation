// lcmとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1001001001
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)
using namespace std;
bool my_compare(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        // どちらも同じ
        return true;
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    ll h,w;
    cin>>h>>w;
    f=2;
    //vector<vector<ll>> v(h,vector<ll> (w));
    vector<string> s(h);
    rep(i,h)  cin>>s[i];
    rep(i,h){
        f=1;
        rep(j,w){
            if(s[i][j]!='.') f=0;
        }
        if(f==1){
            for(ll k=i;k<h-1;k++){
            rep(j,w) s[k][j]=s[k+1][j];
            }
            h--;
            i--;
        }
    }
    rep(j,w){
        f=1;
        rep(i,h){
            if(s[i][j]!='.') f=0;
        }
        if(f==1){
            for(ll k=j;k<w-1;k++){
                rep(i,h) {
                    s[i][k]=s[i][k+1];
                    s[i][k+1]=' ';
                }
                
            }
            w--;
            j--;
        }
    }
    //cout<<w<<endl;
        f=1;
        rep(i,h){
            if(s[i][w]!='.') f=0;
        }
        if(f==1){

                rep(i,h) {
                    s[i][w]=' ';
                }
                
            
            w--;
            
        }

    rep(i,h) cout<<s[i]<<endl;
    


    


    return 0;
}
