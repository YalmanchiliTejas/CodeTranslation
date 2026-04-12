#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
int main(){
    int n,H[105],max=-1,ans=0;
    cin>>n;
    REP(i,n) cin>>H[i];
    REP(i,n){
        if(H[i]>=max){
            ans++;
            max=H[i];
        }
    }
    cout<<ans<<endl;
}