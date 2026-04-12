#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int x;
    cin >> x;
    switch(x){
        case 7:
        case 5:
        case 3:
            cout << "YES" << endl;
            break;
        default:
            cout << "NO" << endl;
            break;
    }
    return 0;
}