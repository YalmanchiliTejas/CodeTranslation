#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ull  unsigned long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 500000;
int a[N];
int naive(){
    int res = 0;
    while(a[0] >= 2 || a[1] >= 2){
        if (a[0] > 2){
            a[0] -= 2;
            a[1]++;
        } else{
            a[0]++;
            a[1] -= 2;
        }
        res++;
    }
    return res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("ou tput.txt", "w", stdout);
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= 1e15; i++){
        int x = 0;
        int y;
        for (int j = 1; j <= n; j++){
            if (a[j] > x){
                x = a[j];
                y = j;
            }
        }
        if (x < n){
            cout << ans;
            return 0;
        }
        int t = (x - n) / n + 1;
        ans += t;
        for (int j = 1; j <= n; j++){
            if (j != y) a[j] += t; else a[j] -= t * n;
        }
    }
}
