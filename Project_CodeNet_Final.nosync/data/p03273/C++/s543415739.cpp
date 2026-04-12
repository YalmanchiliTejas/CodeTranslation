#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const long long inf = 1e9+7;
const long long mod = 1e9+7;

int main(){
    int h,w;
    cin>>h>>w;

    vector<vector<char>>a(h,vector<char>(w));
    rep(i,h){
        rep(j,w)
            cin>>a[i][j];
    }

    vector<int>H(h,0),W(w,0);

    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#'){
                H[i]=1;
                W[j]=1;
            }
        }
    }

    rep(i,h){
        if(H[i]==1){
            rep(j,w){
                if(W[j]==1){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
}
