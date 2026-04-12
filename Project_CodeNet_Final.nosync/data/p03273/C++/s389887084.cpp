#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll h,w;
    cin>>h>>w;
    vector<string> a(h);
    vector<bool> bx(w,0),by(h,0);
    for(ll i=0;i<h;i++){
        cin>>a[i];
        for(ll j=0;j<w;j++){
            if(a[i][j]=='#'){
                by[i]=1;
                bx[j]=1;
            }
        }
    }
    for(ll i=0;i<h;i++){
        if(by[i]){
            for(ll j=0;j<w;j++){
                if(bx[j]){
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}