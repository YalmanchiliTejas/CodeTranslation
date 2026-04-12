#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;

int n,l,r,ans,ok;
vector<int> A(MAX_N);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> n >> l >> r,n){
        for (int i=0;i<n;++i) cin >> A[i];
        ans=0;
        for (int x=l;x<=r;++x){
            ok=-1;
            for (int i=0;i<n;++i){
                if (x%A[i]==0){ok=i+1; break;}
            }
            if (ok<0&&!(n&1)) ++ans;
            if (ok>=0&&(ok&1)) ++ans;
        }
        cout << ans << '\n';
    }
}
