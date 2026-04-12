#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    int cnt=0;

    rep(i,h){
        rep(j,w){
            char a;cin>>a;
            if(a=='#'){
                cnt++;
            }
        }
    }

    if(cnt==h+w-1){
        cout<<"Possible"<<endl;
        return 0;
    }
    cout<<"Impossible"<<endl;

}
