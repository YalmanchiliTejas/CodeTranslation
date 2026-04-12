#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X, Y, Z;
    cin>>X>>Y>>Z;
    cout<<(X - Z) / (Y + Z)<<endl;

    return 0;
}