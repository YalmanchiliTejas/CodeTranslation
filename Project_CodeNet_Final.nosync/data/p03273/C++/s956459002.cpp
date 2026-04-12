#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;

    vector<string>a(h);
    rep(i,h){
            cin>>a[i];
    }

    vector<bool>H(h,false),W(w,false);

    rep(i,h){
        rep(j,w){
            if(a[i][j]=='#'){
                H[i]=true;
                W[j]=true;
            }
        }
    }

    rep(i,h){
        if(H[i]){
            rep(j,w){
                if(W[j]){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
}

