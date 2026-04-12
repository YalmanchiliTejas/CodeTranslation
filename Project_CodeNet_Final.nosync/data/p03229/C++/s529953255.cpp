#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<long long> a(n,0);
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(),a.end());

    long long z; int m=n/2;
    if(n&1) {
        // -2, -2, -2, -2, 1, 1, 2, 2, 2
        // -2, -2, -2, -1, -1, 2, 2, 2, 2
        z = - accumulate(a.begin(), a.begin()+m,0L) 
        + accumulate(a.begin()+m, a.end(),0L);
        z *= 2;
        z += max(-a[m] - a[m+1],a[m-1] - 3*a[m]);
    } else {
        z = - accumulate(a.begin(), a.begin()+m,0L) 
        + accumulate(a.begin()+m, a.end(),0L);
        z *= 2;
        z -= -a[m-1] + a[m];
    }
    cout << z << endl;

    return 0;
}
