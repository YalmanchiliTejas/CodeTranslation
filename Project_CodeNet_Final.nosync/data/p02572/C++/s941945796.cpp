#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; unsigned long long int x;
    vector<unsigned long long int> a;
    vector<unsigned long long int> b;

    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> x; a.push_back(x);
        b.push_back(x);
        if (i!=0) {b[i]+=b[i-1];}
    }

    long long int sum=0;
    long long int mod=1000000007;

    for (int i=1;i<n;i++)
    {
        sum+=((a[i]%mod)*(b[i-1]%mod))%mod;
    }
    cout << sum%mod << endl;

    cin.sync();cin.get();
    return 0;
}
