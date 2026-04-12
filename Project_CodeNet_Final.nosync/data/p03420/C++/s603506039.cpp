#include<iostream>
using namespace std;

int main()
{
    long long answer = 0;
    long long n, k;
    cin >> n >> k;
    if(k == 0){
        cout << n * n << endl;
        return 0;
    }
    for(long long i = k + 1; i <= n; i++){
        long long loop = i - k;
        answer += loop * (n / i);
        if((n - (n / i) * i + 1) - k > 0){
            answer += (n - (n / i) * i + 1) - k;
        }
    }
    cout << answer << endl;
    return 0;
}