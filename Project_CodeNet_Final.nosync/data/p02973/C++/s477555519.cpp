#include <iostream>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int p[N];
    fill(p, p+N, -1);
    for(int i=0; i<N; i++){
        auto it = lower_bound(p, p+N, A[i]);
        it--;
        *it = A[i];
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        if(p[i] != -1) ans++;
    }

    cout << ans << endl;

    return 0;
}
