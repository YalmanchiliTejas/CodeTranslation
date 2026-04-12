#include <iostream>
#include <map>
#include <cassert>
using namespace std;
typedef long long ll;
int N;
ll S[100010];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> S[i];
    ll ans = 0;
    for(int C=1;C<=N-1;C++){
        ll now = 0;
        for(int k=0;k*C<=N-1;k++){
            int A = N-1-k*C,B = A-C;
            now = now+S[N-1-k*C]+S[k*C];
            if(A<=B || B<=0) continue;
            if(A%C==0 && A/C<=k) continue;
            ans = max(ans,now);
        }
    }
    cout << ans << endl;
}