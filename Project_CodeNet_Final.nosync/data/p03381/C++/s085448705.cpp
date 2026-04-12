#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int x[n];
    rep(i, 0, n) cin >> x[i];
    int s[n];
    rep(i, 0, n) s[i] = x[i];

    sort(s, s + n);
    
    int center = (n - 1) / 2;
    rep(i, 0, n)
    {
        if (x[i] <= s[center])
            cout << s[center + 1] << endl;
        else
            cout << s[center] << endl;
    }


    return 0;
}