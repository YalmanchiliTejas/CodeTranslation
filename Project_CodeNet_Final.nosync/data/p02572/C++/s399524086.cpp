#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<unsigned long long> X(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = N-1; i > 0; i--)
    {
        X[i] = A[i];
        if (i < N - 1)
            X[i] += X[i + 1];
            X[i] %= 1000000007;
    }
    long long sum = 0;
    for (int i = 0; i < N - 1; i++)
    {

        long long num = A[i] * X[i+1] % 1000000007;
        sum += num;
    }
    sum %= 1000000007;
    cout << sum;
    return 0;
}