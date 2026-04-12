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
        //if((N-1)%C!=0) continue;
        ll now = 0;
        for(int k=0;k*C<=N-1;k++){
            int A = N-1-k*C,B = A-C;
            now = now+S[N-1-k*C]+S[k*C];
            if(A<=B || B<=0) continue;
            if(A%C==0 && A/C<=k) continue;
            ans = max(ans,now);
//            cerr << "A:" << A << " B:" << B << " k:" << k << " C:" << C << " now:" << now << endl;
        }
        /*int C2 = (N-1)/C;
        now = 0;
        for(int k=0;k*C2<=N-1;k++){
            int A = N-1-k*C2,B = A-C2;
            now = now+S[N-1-k*C2]+S[k*C2];
            if(A<=B || B<=0) continue;
            if(A%C2==0 && A/C2<=k) continue;
            ans = max(ans,now);
        }*/
    }
    cout << ans << endl;
}