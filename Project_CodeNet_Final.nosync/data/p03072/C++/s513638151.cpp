#include <iostream>
#include <vector>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, 0, n){
        cin >> h[i];
    }
    int state = h[0];
    int ans = 1;
    rep(i, 1, n){
        if(state <= h[i]){
            ans++;
            state = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}
