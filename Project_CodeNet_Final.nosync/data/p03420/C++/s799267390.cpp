#include <bits/stdc++.h>
using namespace std;
 
using tpl = tuple<char, int>;
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N, K;

int main(){


    cin >> N >> K;
    ll ans = 0;
    if(K == 0){
        ans = (ll)N * N;
    }
    else{
        for(int b = K + 1; b <= N; b++){
            ans += (ll)(N / b) * (b - K);
            ans += max(N % b - K + 1, 0);
        }
    }

    cout << ans << endl;
    


    return 0;
}
