#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long A;
    long long M = 1000000007;
    long long sum = 0;
    long long diag = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        sum = (sum + A) % M;
        diag = (diag + A * A)%M;
    }
    long long tmp = sum * sum - diag;
    tmp = ((tmp & 1)==0) ? tmp : (tmp + M); 
    long long ret = (tmp / 2) % M;
    cout << ret;
    return 0;
}