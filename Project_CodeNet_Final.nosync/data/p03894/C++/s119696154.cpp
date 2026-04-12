#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int A[100000], B[100000];

bool ok[100000];
int cur = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    ok[1] = true;
    for(int i = 0; i < Q; i++){
        if(cur == A[i]) cur = B[i];
        else if(cur == B[i]) cur = A[i];
        if(ok[A[i]]) {
            if(!ok[B[i]]) ok[A[i]] = false;
            ok[B[i]] = true;
        }
        else if(ok[B[i]]) {
            if(!ok[A[i]]) ok[B[i]] = false;
            ok[A[i]] = true;
        }
        if(cur > 0) ok[cur-1] = true;
        if(cur < N-1) ok[cur+1] = true;
    }
    ok[cur] = true;
   
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(ok[i]) {
            ans++;
        }
    }
    cout << ans << endl;
}