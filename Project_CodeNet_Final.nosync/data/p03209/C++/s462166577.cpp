#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll pat[52];
ll siz[52];

int main(){
    int n;
    cin >> n;
    pat[0] = 1;
    siz[0] = 1;
    for ( int i = 1; i <= n; ++i ) {
        pat[i] = pat[i-1] * 2 + 1;
        siz[i] = siz[i-1] * 2 + 3;
    }
    ll x;
    cin >> x;
    ll ret = 0;
    while(n>0 && x>0) {
        if (x>=2+2*siz[n-1]) {
            ret+=1+2*pat[n-1];
            x=0;
            break;
        }
        if(x>=2+siz[n-1]) {
            ret+=1+pat[n-1];
            x-=2+siz[n-1];
        }
        else if (x==1+siz[n-1]) {
            ret+=pat[n-1];
            x-=1+siz[n-1];
        }
        else {
            --x;
        }
        --n;
    }
    //if (x) ++ret;
    cout << ret << endl;
    return 0;
}
