#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int p[N];
    fill(p, p+N, -1);
    p[0] = A[0];
    sort(p, p+N);
    for(int i=1; i<N; i++){
        int ind = lower_bound(p, p+N, A[i])-p;
        p[ind-1] = A[i];
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        if(p[i] != -1) ans++;
    }

    cout << ans << endl;

    return 0;
}