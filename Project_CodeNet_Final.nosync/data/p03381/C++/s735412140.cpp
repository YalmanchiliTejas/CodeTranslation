#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5+7;
int n;
int a[N],h[N],pos[N];
bool cmp(int i,int j) {
    return a[i] < a[j];
}
void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        h[i] = i;
    }
    sort(h + 1,h + 1 + n,cmp);
    for (int i = 1; i <= n; i++) {
        pos[h[i]] = i;
    }
}
void solve()
{
    int mid = n >> 1;
//    for (int i = 1; i <= n; i++) {cout << h[i] << " ";}
//    cout << '\n';
    for (int i = 1; i <= n; i++) {
        if (pos[i] <= mid) {
            cout << a[h[mid + 1]] << '\n';
        }
        else {
            cout << a[h[mid]] << '\n';
        }
    }
}
int main()
{
    nhap();
    solve();
}
