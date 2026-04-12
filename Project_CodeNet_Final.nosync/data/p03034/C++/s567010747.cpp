#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<long long> s(N);
    for (long long &t: s)
        cin>>t;

    long long ans = 0;
    for (int d=1; d<N; d++)
    {
        long long a = 0;
        int l = d;
        int r = N-1-d;
        while (l<N-1)
        {
            if (l==r || l==r+d || r<d)
                break;

            a += s[l];
            a += s[r];
            ans = max(ans, a);

            l += d;
            r -= d;
        }
    }
    cout<<ans<<endl;
}
