#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    long long sum=0;
    const long long mod = 1e9+7;
    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++)
    {
        cin >> v[i];
        sum += v[i];
        sum %= mod;
    }
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        sum -= v[i];
        if (sum < 0) sum += mod;
        ans += v[i]*sum;
        ans %= mod;
    }
    cout << ans;
    
    return 0;
}