#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll h,w;cin>>h>>w;
    char a[h][w];for(ll i=0;i<h;i++)cin>>a[i];
    ll cur=0;
    for(ll i=0;i<h;i++){
        ll s=-1;
        for(ll j=0;j<w;j++){
            if(a[i][j]=='#'){
                s=j;
                break;
            }
        }

        if(s==-1)return cout<<"Impossible" , 0;

        ll e=w;
        for(ll j=w-1;j>=0;j--){
            if(a[i][j]=='#'){
                e=j;
                break;
            }
        }

        for(ll j=s;j<=e;j++)if(a[i][j]!='#')return cout<<"Impossible" , 0;

        if(s!=cur)return cout<<"Impossible"  , 0;
        cur=e;
    }
    cout<<"Possible";
}

