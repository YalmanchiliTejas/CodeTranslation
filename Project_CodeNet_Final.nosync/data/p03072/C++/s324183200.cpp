#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long int
#define FOR(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n)

using namespace std;

int main()
{
    int n, highest, ans = 1;
    cin >> n;
    int h[n];
    cin >> h[0];
    highest = h[0];
    REP1(i,n){
        cin >> h[i];
        if(highest <= h[i]){
            ans += 1;
            highest = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}
