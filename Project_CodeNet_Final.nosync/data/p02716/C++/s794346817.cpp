//#pragma GCC optimize("O3")
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;
function<void(void)> ____ = [](){ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);};
const int MAXN = 2e5+7;
using LL = int_fast64_t;
int n;
LL A[MAXN],f[MAXN];
int main(){
    ____();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    if(!(n&1)){
        f[1] = A[1]; f[2] = A[2];
        for(int i = 2; i <= n / 2; i++){
            f[i*2] = max(f[(i-1)*2-1],f[(i-1)*2]) + A[i*2];
            f[i*2-1] = f[(i-1)*2-1] + A[i*2-1];
        }
        cout << max(f[n],f[n-1]) << endl;
    }
    else{
        f[1] = A[1]; f[2] = A[2]; f[3] = A[3];
        for(int i = 2; i <= n / 2; i++){
            f[i*2+1] = max(max(f[(i-1)*2-1],f[(i-1)*2]),f[(i-1)*2+1]) + A[i*2+1];
            f[i*2] = max(f[(i-1)*2-1],f[(i-1)*2]) + A[i*2];
            f[i*2-1] = f[(i-1)*2-1] + A[i*2-1];
        }
        cout << max(max(f[n],f[n-1]),f[n-2]) << endl;
    }
    return 0;
}