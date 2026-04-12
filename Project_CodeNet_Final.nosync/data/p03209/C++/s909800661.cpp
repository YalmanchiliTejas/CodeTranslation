#include <iostream>

using namespace std;

typedef long long ll;

ll N,X;
ll s[51];
ll p[51];

ll dfs(ll L,ll x){
    if(L == 0) return 1;
    if(s[L] == x) return p[L];
    if(x == 1) return 0;
    if(x <= 1 + s[L-1]) return dfs(L-1,x-1);
    if(x == 2 + s[L-1]) return p[L-1] + 1;
    return p[L-1] + 1 + dfs(L-1,x-2-s[L-1]);
}

int main(){
    cin >> N >> X;
    s[0] = p[0] = 1;
    for(int i=1;i<=50;i++){
        s[i] = s[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }
    cout << dfs(N,X) << endl;
    return 0;
}