#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;

ll bans[51]; // レベルNバーガーの長さ
ll pat[51]; // レベルNバーガーにパティが何枚あるか


// levelバーガーをしたからx枚のとき，何枚のパティを食べれるか
ll eat(ll L, ll x){

    if(x == 0) return 0;
    else if(x == 1){
        if(L == 0) return 1;
        else return 0;
    }
    else if(x <= 1 + bans[L-1]){
        return eat(L - 1, x - 1);
    }
    else if(x <= bans[L] - 1){
        return pat[L - 1] + eat(L - 1, x - 2 - bans[L - 1] ) + 1;
    }
    else if(x == bans[L]){
        return pat[L];
    }

}

int main(){

    ll N, X;
    cin >> N >> X;

    bans[0] = 1;
    for(int i = 1; i <= N; i++){
        bans[i] = 2 * bans[i-1] + 3;
    }
    

    pat[0] = 1;
    for(int i = 1; i <= N; i++){
        pat[i] = 2 * pat[i-1] + 1;
    }

    cout << eat(N, X) << endl; 


}

