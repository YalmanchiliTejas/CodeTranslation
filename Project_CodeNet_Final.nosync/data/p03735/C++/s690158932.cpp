#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    vector<pair<int64_t, int64_t>> BA(N);
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
        if(A[i] < B[i]) swap(A[i], B[i]);
        BA[i] = {B[i], A[i]};
    }
    int64_t Amax = *max_element(A.begin(), A.end());
    int64_t Amin = *min_element(A.begin(), A.end());
    sort(BA.begin(), BA.end());
    int64_t Bmin = BA[0].first, Bmax = BA[N-1].first;
    int64_t ans = (Amax-Amin) * (Bmax-Bmin);
    int64_t Amin0 = Amin;

    for(int i=0; i<N-1; i++){
        int64_t b = BA[i].first, a = BA[i].second;
        if(b >= Amin0) break;
        Bmin = min(Amin0, BA[i+1].first);
        Amin = min(Amin, b);
        Bmax = max(Bmax, a);
        ans = min(ans, (Amax-Amin) * (Bmax-Bmin));
    }
    cout << ans << endl;
}