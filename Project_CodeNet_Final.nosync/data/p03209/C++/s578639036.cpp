#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1001001001;

ll cnt[51];
ll patty[51];

ll f(int n, ll x);

int main(){
    int N;
    ll X;
    cin >> N >> X;
    
    cnt[0] = 1;
    patty[0] = 1;
    for(int i = 1; i <= 50; ++i){
        cnt[i] = 2 * cnt[i - 1] + 3;
        patty[i] = 2 * patty[i - 1] + 1;
    }
    
    cout << f(N, X) << endl;
}

ll f(int n, ll x){
    if(n == 0)      return 1;
    
    // 左半分で分けるとき
    if(x == 1)      return 0;
    if(x > 1 && x <= cnt[n - 1] + 1)    return f(n - 1, x - 1);
    
    // 真ん中で分けるとき
    if(x == cnt[n - 1] + 2)     return patty[n - 1] + 1;
    
    // 右半分で分けるとき
    if(x > cnt[n - 1] + 2 && x <= 2 * cnt[n - 1] + 2)
        return patty[n - 1] + 1 + f(n - 1, x - cnt[n - 1] - 2);
        
    // 一番右端(x == 2 * cnt[n - 1] + 3)    
    return 2 * patty[n - 1] + 1;    
}