#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REP_(i, a, b) for(int i = a; i <= b; i++)
#define sl(n) scanf("%lld", &n);
#define si(n) scanf("%d", &n);
#define RepAll(a) for(auto x: a)
#define cout(ans) cout << ans << endl;
typedef long long ll;
ll a[10010];
using namespace std;
int main(){
    ll n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll cnt = 0;
            /*
            sort(a, a+n);
            if(a[n - 1] < n){
               cout << "0" << endl;
               continue;
            }
            else{
                for(int i = n-1; i >= 0&& a[i] >= n; i--){
                    cnt += (a[i] - n - 1)/n + 1;
                }
            */
    while(1){
        ll maxn = a[0], index = 0;

        for(int i = 0; i < n; i++){
           if(a[i] > maxn){
                maxn = a[i];
                index = i;
        }
        }
        if(maxn <= n-1) {
            break;
        }
        for(int i = 0; i <= n; i++){
            if(i == index)
            {
                a[i] = maxn%n; //最后剩下的数字
            }
            else
            {
                a[i] += maxn/n; //需要加的步数
            }
        }
        cnt += (maxn/n);
    }
    cout << cnt << endl;

    }
    return 0;
}