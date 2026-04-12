#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    long long acm = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        acm += A[i];
        acm %= MOD;
    }

    long sum = 0;

    //i について全探索する
    for (int i = 0; i < N; i++)
    {
        //A[i+1] ... A[N] の値を更新する
        acm -= A[i];
        if (acm < 0) acm += MOD;

        sum += A[i] * acm;
        sum %= MOD;
    }

    cout << sum << endl;
}
