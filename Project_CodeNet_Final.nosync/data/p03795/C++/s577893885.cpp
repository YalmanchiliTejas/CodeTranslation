#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
#define per(i,n,a) for (int i = n-1;i >= a;i--)
using namespace std;

int main() {
    int n; cin >> n;
    cout << n * 800 - (n / 15) * 200 << endl;
}