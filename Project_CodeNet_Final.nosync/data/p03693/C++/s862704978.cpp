#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string YES = "YES";
const string NO = "NO";

void solve(long long r, long long g, long long b){
    ll res = r*100+g*10+b;
    if(res % 4 == 0) cout << YES << endl;
    else cout << NO << endl;
}

int main(){
    long long r;
    scanf("%lld",&r);
    long long g;
    scanf("%lld",&g);
    long long b;
    scanf("%lld",&b);
    solve(r, g, b);
    return 0;
}
