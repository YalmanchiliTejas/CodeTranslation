#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const long long mod = 1000000007;
    
int main()
{
    long n;
    cin >> n;
    vector<long long> x(n+1);
    for(size_t i=1; i<x.size(); i++)
        cin >> x[i];

    auto solver = [&](){
        long long sum=0;
        long long t=0;
        for(long i=n-1; i>0; i--){
            t = (t + x[i+1]) % mod;
            sum += (t * x[i]) % mod;
            sum %= mod;
        }
        return sum;
    };
    
    cout << solver() << endl;

    return 0;
}
