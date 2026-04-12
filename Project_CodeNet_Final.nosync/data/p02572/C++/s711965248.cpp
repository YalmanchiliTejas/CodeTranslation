#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin >> n;
    vector <long long> qw (n);
    vector <long long> kn (n);
    long long r=0;
    long long t=0;
    for (int i=0; i<n; ++i)
    {
        cin >> qw[i];
        r+=qw[i];
        r%=1000000007;
        kn[i]=r;
    }
    int y=0;
    for (int i=0; i<n; ++i)
    {
        long long q=(r-kn[i]+1000000007)%1000000007;
        t+=q*qw[i];
        t%=1000000007;
    }
    cout << t << endl;
}
