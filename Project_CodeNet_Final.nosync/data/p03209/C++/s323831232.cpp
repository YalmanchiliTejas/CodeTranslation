#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
#define reps(i, s, e) for(int i=s; i<e; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define reprs(i, s, e) for(int i=e-1; i>=s; i--)

int main(){

    ll n, x; cin >> n >> x;

    ll nlayer[n];
    ll npatty[n];
    nlayer[0] = 1;
    npatty[0] = 1;
    reps(i, 1, n+1){
        nlayer[i] = 3 + 2*nlayer[i-1];
        npatty[i] = 1 + 2*npatty[i-1];
        // cout << nlayer[i] << " " << npatty[i] << endl;
    }

    ll ans = 0;
    repr(i, n+1){
        if(x > nlayer[i]) x = nlayer[i];
        // cout << i << " " << nlayer[i] << " " << x << " " << ans << endl;

        if(i == 1){
            if(x == 2){
                ans += 1;
            }
            else if(x == 3){
                ans += 2;
            }
            else if(x == 4 || x == 5){
                ans += 3;
            }
            break;
        }

        ll center = (nlayer[i] + 1)/2;
        // cout << " " << center << endl;
        if(x == center){
            ans += npatty[i-1] + 1;
            break;
        }
        else if(x > center){
            x -= center;
            ans += npatty[i-1] + 1;
        }
        else if(x < center){
            x -= 1;
        }

        // cout << " " << x << endl;
    }

    cout << ans;

    return 0;
}