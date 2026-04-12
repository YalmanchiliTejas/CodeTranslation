#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back

int dfa[51]={};
int fa(int n){
    if(dfa[n]!=0)return dfa[n];
    if(n==0)return 1;
    else return dfa[n] = fa(n-1)*2+3;
}

int dfp[51]={};
int fp(int n){
    if(dfp[n]!=0)return dfp[n];
    if(n==0)return 1;
    else return dfp[n] = fp(n-1)*2+1;
}

signed main(){
    int n,x;
    cin>>n>>x;

    int ans = 0;
    while(x>0){
        for(int i=n;i>=0;i--){
            if(x>=fa(i)){
                x-=fa(i);
                ans+=fp(i);

                if(x>0){
                    x--;
                    ans++;
                }

                n = i;
                break;
            }else{
                x--;
            }
        }
    }

    cout<<ans<<endl;
}
