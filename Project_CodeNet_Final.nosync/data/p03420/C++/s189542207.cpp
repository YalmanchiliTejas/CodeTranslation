#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

int main() {
    ll N,K;
    cin >> N >> K;
    ll ans=0;
    if(K==0){
        cout << N*N << endl;
        return 0;
    }
    for(int b=K+1;b<=N;b++){
        ans+=N/b*(b-K);
        ans+=max(N%b-K+1,(ll)0);
    }
    cout << ans << endl;

    return 0;
}