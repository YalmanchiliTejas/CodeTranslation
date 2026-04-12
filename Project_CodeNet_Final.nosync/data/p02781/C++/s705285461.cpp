#include<bits/stdc++.h>
using namespace std;

int f(int n, int r) {
    int ans = 1;
    for (int i=1; i<=r; i++)    ans = (ans * (n+1-i));
    for (int i=1; i<=r; i++)    ans = ans/i;
    for (int i=1; i<=r; i++)    ans = ans*9;
    return ans;
}

string s;
int n, k;

const int N = 105;

int solve(int i, int cur) {
    if (cur == k)   return 1;
    if (i == n)     return 0;

    int dd = s[i] - '0';
    if (dd == 0)    return solve(i+1, cur);

    int rem = n-i-1;
    int ans = f(rem, k - cur);
    for (int d=1; d < dd; d++)  ans += f(rem, k - cur - 1);
    ans += solve(i+1, cur+1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>s>>k;
    n = s.size();

    cout<<solve(0, 0);
}
