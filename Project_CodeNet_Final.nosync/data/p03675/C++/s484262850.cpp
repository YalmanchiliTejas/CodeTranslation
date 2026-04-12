#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1e9+7

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    vector<int> b(n);

    int idx = n/2,r = n-1,l = 0,j = 0;

    for(int i = n-1;i >= 0;i--)
    {
        if(j%2==0){ b[l] = a[i]; l++; }
        else{ b[r] = a[i]; r--; }
        j++;
    }

    for(int i = 0;i < n;i++) cout << b[i] << ' ';

}
