#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int INF = 1 << 20;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        ll p; cin >> p;
        ll y; cin >> y;
        ll m; cin >> m;
        ll ans = 0;
        for(int j = 0; j < m; j++){
            ll a; cin >> a;
            double b; cin >> b;
            ll c; cin >> c;
            ll now = p;
            ll add = 0;
            if(a == 0){
                for(int k = 0; k < y; k++){
                    add += now * b;
                    now -= c;
                }
                ans = max(ans,now+add);
            }else{
                for(int k = 0; k < y; k++){
                    now += now*b;
                    now -= c;
                }
                ans = max(ans,now);
            }
        }
        cout << ans << endl;
    }
}
