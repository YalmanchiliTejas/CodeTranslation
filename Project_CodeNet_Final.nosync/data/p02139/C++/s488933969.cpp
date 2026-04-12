#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back

signed main(){
    int n,q;
    cin>>n>>q;
    int diff = 0;
    rep(i,q){
        int type, k;
        cin>>type>>k;
        if(type==0)cout<<(k-1-diff+n)%n+1<<endl;
        else diff = (diff-k+n)%n;
    }
}

