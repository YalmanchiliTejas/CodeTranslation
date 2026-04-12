#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int r,g,b;
    cin >> r >> g >> b;
    int x = r*100+g*10+b;
    if(x%4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}