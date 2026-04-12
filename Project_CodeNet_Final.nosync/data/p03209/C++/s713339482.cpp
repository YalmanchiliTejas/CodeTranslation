#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll N,X,Pat[51],Lay[51],L,ans;

ll count(ll X,ll L){
    if(X==0)return 0;
    if(X==Lay[L])return Pat[L];
    if(X>=(Lay[L]+1)/2) return (Pat[L]+1)/2 + count(X-(Lay[L]+1)/2,L-1);
    else return count(X-1,L-1);
}

int main(void){
    cin >> N >> X;
    Pat[0] = 1,Lay[0]=1;
    rep(i,N){
        Pat[i+1] = 2*Pat[i]+1;
        Lay[i+1] = 2*Lay[i]+3;
        //cout << Pat[i+1] << " " << Lay[i+1] << endl;
    }
    
    cout << count(X,N)<<endl;
    
}
