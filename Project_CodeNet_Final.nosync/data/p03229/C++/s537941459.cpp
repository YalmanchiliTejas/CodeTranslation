#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);

    ll ans = 0;
    if(n % 2 == 0){
        int div = n / 2;
        for(int i = 0; i < n; i++){
            if(i < div-1){
                ans -= (a[i]*2);
            }else if(i == div-1){
                ans -= a[i];
            }else if(i == div){
                ans += a[i];
            }else{
                ans += (a[i]*2);
            }
        }
        cout << ans;
    }else{
        ll tmp1 = 0,tmp2 = 0;
        int div = n / 2;
        for(int i = 0; i < n; i++){
            if(i < div){
                tmp1 -= (a[i]*2);
            }else if(i == div || i == div+1){
                tmp1 += a[i];
            }else{
                tmp1 += (a[i]*2);
            }
        }
        for(int i = 0; i < n; i++){
            if(i < div-1){
                tmp2 -= (a[i]*2);
            }else if(i == div-1 || i == div){
                tmp2 -= a[i];
            }else{
                tmp2 += (a[i]*2);
            }
        }
        if(tmp1 < tmp2){
            cout << tmp2;
        }else{
            cout << tmp1;
        }
    }
}
