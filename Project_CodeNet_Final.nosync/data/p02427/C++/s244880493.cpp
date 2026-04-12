#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repd(i,a,b) for (int i = (a); i < (b); i++)
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    
    rep(i, pow(2, n))
    {
        bitset<18> bit(i);
        cout << i << ":";
        rep(j, 18)
        {
            if (bit.test(j)) cout << " " << j;
        }
        cout << endl;
    }
}

