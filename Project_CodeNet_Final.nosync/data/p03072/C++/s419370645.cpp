#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(void)
{
    int N, H, max = 0, count = 0;
    
    cin >> N;
    
    rep (i, N)
    {
        cin >> H;
        if (max <= H)
        {
            count++;
            max = H;
        }
    }
    
    cout << count << endl;
}
