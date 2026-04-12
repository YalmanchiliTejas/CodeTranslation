#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];

    sort(A.begin(), A.end());

    long long S;
    if (N % 2 == 0){
        int c = N / 2;
        S = -2 * accumulate(A.begin(), A.begin() + c, 0LL) + 2 * accumulate(A.begin() + c, A.end(), 0LL) + A[c-1] - A[c];
    }
    else{
        int c = (N - 1) / 2;
        long long tmp1 = -2 * accumulate(A.begin(), A.begin() + c, 0LL) + 2 * accumulate(A.begin() + c + 2, A.end(), 0LL) + A[c] + A[c+1];
        long long tmp2 = -2 * accumulate(A.begin(), A.begin() + c-1, 0LL) + 2 * accumulate(A.begin() + c + 1, A.end(), 0LL) - A[c-1] - A[c];
        S = max(tmp1, tmp2);
    }

    cout << S << endl;
    return 0;
}