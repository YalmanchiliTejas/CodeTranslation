#include <bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;
typedef long long  ll;
const int N = 1e4 + 4 , MOD = 1e9 + 7;

string s;
int d , memo[N][104][2];

int add(int a , int b){
    return (1ll * a + b) % MOD;
}

int solve(int indx , int rem , bool gr){
    if(indx == (int)s.size())
        return !rem;

    int &ret = memo[indx][rem][gr];
    if(~ret)
        return ret;

    ret = 0;
    int theOne = s[indx] - '0' , en = (gr ? 9 : theOne);
    for(int i = 0 ; i <= en ; ++i)
        ret = add(ret , solve(indx + 1 , (rem + i) % d , gr | (i < theOne)));
    return ret;
}
int main() {
    ios::sync_with_stdio() , cin.tie(0) , cout.tie();
    cin >> s;

    cin >> d;

    memset(memo , -1 , sizeof memo);

    cout << (solve(0 , 0 , false) - 1 + MOD) % MOD << '\n';
}
