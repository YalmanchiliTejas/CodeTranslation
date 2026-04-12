#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = int(1e8) + 7;

void init(){

}

void solve(){
    int n;
    scanf("%d", &n);
    int ans = 1;
    int m;
    scanf("%d", &m);
    for(int i = 0; i < n-1; i++){
        int p; scanf("%d", &p);
        if(p >= m){
            m = p;
            ans++;
        }
    }
    printf("%d\n", ans);
}

const bool mtc = false;

int main(){
    int t;
    if(mtc){
        scanf("%d", &t);
        while(t--) solve();
    }
    else solve();
}

