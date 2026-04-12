#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n; cin >> n;
    long long int lst[100010];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        long long int a; cin >> a;
        
        bool dn = false;
        if (l == 0) {
          lst[0] = a;
          l ++;
          continue;
        }
        if (a <= lst[l-1]) {
            lst[l] = a;
            l ++;
            continue;
        }
        if (a > lst[0])
        {
            lst[0] = a;
            continue;
        }

        int f = 0, r = l-1;

        while (r-f>1)
        {
            int m = (f+r)/2;
            if (a > lst[m]) {
                r = m;
            }
            else {
                f = m;
            }
        }
        lst[r] = a;


    }
    cout << l << endl;
    return 0;
}
