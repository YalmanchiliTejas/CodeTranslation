#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>

using namespace std;

long n, x;
long ans = 0;
long countP[51];

void rec(int nn, long from, long to)
{
    if(from < 0 || to < 0 || ans<0) return;

    if(nn == 0)
    {
        ans++;
        return;
    }

    long midP = from + (to - from)/2;

    if(x == from) return;
    else if(x < midP)
    {
        rec(nn-1, from + 1, midP-1);
    }
    else if(x == midP)
    {
        ans += countP[nn-1] + 1;
    }
    else if(x == to || x == to - 1)
    {
        ans += countP[nn];
    }
    else
    {
        ans += countP[nn-1] + 1;
        rec(nn-1, midP+1, to-1);
    }

}

int main() {

    countP[0] = 1;
    for(int i=1; i<=50; i++)
    {
        countP[i] = countP[i-1] * 2 + 1;
    }

    cin >> n;
    cin >> x;

    long len = 1;
    for(int i=1; i<=n; i++) len = len * 2 + 3;

    rec(n, 1, len);

    cout << ans << endl;
}