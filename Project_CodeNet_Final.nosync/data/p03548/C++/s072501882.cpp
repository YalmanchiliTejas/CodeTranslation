#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1e9;

using namespace std;

typedef long long ll;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    int cnt = 0;
    while(cnt * (y+z) + z <= x){
        cnt++;
    }
    cout << --cnt << endl;
    return 0;
}