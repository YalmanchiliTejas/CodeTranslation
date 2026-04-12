#include<bits/stdc++.h>
#define pb push_back

typedef long long ll;
using namespace std;

typedef long double ldouble;

const ll MXN = 2e5 + 1;

int n, a[MXN], b[MXN], sum;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    sum = b[n / 2];
    for(int i = 1; i <= n; i ++){
        if(a[i] <= sum) cout << b[(n + 2) / 2] << '\n';
        else cout << b[(n + 1) / 2] << '\n';
    }
    return 0;
}
