#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1e9;

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main()
{
    int r,g,b;
    cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;
    if(num % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}