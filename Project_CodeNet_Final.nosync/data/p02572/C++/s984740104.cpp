#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<long long int>a;
    for(int i=0;i<n;i++)
    {
        long long int t = 0ll;
        cin >> t;
        a.push_back(t);
    }
    // a1(a2+a3+a4+...+aN) + a2(a3+a4+a5+...+aN)
    long long int mod = 1000000007;
    long long int itr_sum = a[n-1];
    long long int ans = 0;
    for(int i=n-2;i>=0;i--)
    {
        ans += (itr_sum*a[i])%mod;
        ans %= mod;
        itr_sum += a[i];
        itr_sum = itr_sum%mod; 
    }
    cout <<ans;
    return 0;
}
