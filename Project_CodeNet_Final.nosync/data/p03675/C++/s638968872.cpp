#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define x first
#define y second
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define MOD 1000000007

using namespace std;
int n, a[200100];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n;i++) cin >> a[i];
    for (int i=n;i>=1;i-=2) cout << a[i] << " ";
    int i = 1;
    if (n & 1) i = 2;
    for (; i<=n; i+=2) cout << a[i] << " ";
}