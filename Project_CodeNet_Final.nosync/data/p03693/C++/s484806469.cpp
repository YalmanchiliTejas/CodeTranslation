#include <bits/stdc++.h>
#define pb push_back
#define S second
#define F first

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
int r[3];
int vis[3];
int rec(int n,int depth){
    if (depth == 3){
        if (n % 4 == 0 )return 1;
        else return 0;
    }
    for (int i = 0;i < 3;i++){
        if (vis[i]) continue;
        vis[i] = 1;
        if (rec(n * 10 + r[i],depth + 1)) return 1;
        vis[i] = 0;
    }
    return 0;
}
int main(){

    cin >> r[0] >> r[1] >> r[2];
    if ((r[0] * 100 + r[1] * 10 + r[2]) % 4 ==0 ){
        cout << "YES\n";
    } else cout << "NO\n";
    return 0;
}
