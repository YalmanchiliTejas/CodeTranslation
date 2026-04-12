#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> A(N);
    long long sum = 0;
    long result = 0;
    long m = 1000000007;
    for (int i = 0 ; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
        sum %= m;
    }

    for (int j = 0 ; j < N; j++) {
        sum -= A[j];
        if (sum < 0) sum += m;

        result += A[j] * sum; 
        result %= m;
    }

    cout << result << endl;
}