#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int x;

int main()
{
    _FastIO;
    cin >> x;
    if(x == 3 || x == 5 || x == 7){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
