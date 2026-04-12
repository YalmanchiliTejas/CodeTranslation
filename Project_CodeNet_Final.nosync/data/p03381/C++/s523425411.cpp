#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int N = 2e5 + 87;
pii a[N];
int b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a,a+n);
    for (int i = 0; i < n/2; ++i)
        b[a[i].S] = a[n/2].F;
    for (int i = n/2; i < n; ++i)
        b[a[i].S] = a[n/2-1].F;
    for (int i = 0; i < n; ++i)
        cout << b[i] << '\n';
}