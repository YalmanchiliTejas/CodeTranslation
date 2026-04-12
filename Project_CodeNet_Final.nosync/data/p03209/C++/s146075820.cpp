#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back

int fa(int n){
    if(n==0)return 1;
    else return fa(n-1)*2+3;
}

int fp(int n){
    if(n==0)return 1;
    else return fp(n-1)*2+1;
}

signed main(){
    int n,x;
    cin>>n>>x;

    int ans = 0;
    while(x>0){
      //今見てるパウンドがLevel N
        for(int i=n;i>=0;i--){  
            if(x>=fa(i)){ //Level　i のバーガーを食べきれるか
                x-=fa(i);
                ans+=fp(i);

                if(x>0){  //Level i を食べた後に間のパウンドを食べる
                    x--;
                    ans++;
                }

                n = i;  //今見てるパウンドを更新(?)
                break;
            }else{  //無理ならLevel i のパンズを食べてLevel i-1に移行
                x--;
            }
        }
    }

    cout<<ans<<endl;
}
