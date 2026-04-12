#include <iostream>
#include <vector>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    int ans = 0;
    int highest = 0;
    vector <ll> H(n, 0);
    for (int i = 0; i < n; i ++){
        cin >> H.at(i);
    }

    for (auto h: H){
        if  (highest<=h) {
            ans += 1;
            highest = h;
        }
    }
    cout << ans;
    return 0;
}