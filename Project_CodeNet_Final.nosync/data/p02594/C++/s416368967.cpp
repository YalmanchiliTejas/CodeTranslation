#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)

const string YES = "Yes";
const string NO = "No";

void solve(long long X){
    string ans = "";
    if(X >= 30) ans = YES;
    else ans = NO;

    cout << ans << endl;

}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
