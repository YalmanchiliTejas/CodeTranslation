#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int n;cin>>n;
    int mx=1;
    int before=1;
    int ans = 0;
    rep(i,n){
        int tmp;cin>>tmp;
        if(before<=tmp)ans++;
        before = max(before, tmp);
    }
    co(ans);
}
