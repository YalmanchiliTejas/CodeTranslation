#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n;
    cin >> n;
    vector<LL> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    LL ans = 0;

    LL m = a[0];
    for(int i = 1; i < n; i++){
        LL ok = 0;
        LL ng = a[i]/n + 1;
        while(abs(ok-ng) > 1){
            LL middle = (ok+ng)/2;
            if((a[i] - middle*n) - (m + middle) < 0){
                ng = middle;
            }else{
                ok = middle;
            }
        }
        ans += ok;
        a[i] -= ok*n;
        for(int j = 0; j < n; j++){
            if(i != j){
                a[j] += ok;
            }
        }
        m = a[0];
    }

    LL dist = m - n + 1;
    if(dist < 0){
    }else{
        ans += dist*n;
        for(int i = 0; i < n; i++){
            a[i] -= dist;
        }
    }
        bool frag = true;
        while(frag){
            frag = false;
            for(int i = 0; i < n; i++){
                if(a[i] >= n){
                    ans++;
                    frag = true;
                    a[i] -= n;
                    for(int j = 0; j < n; j++){
                        if(i != j){
                            a[j]++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    
    
    return 0;
}