#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main(){
    int N, K;
    cin >> N >> K;
    
    ll res = 0;
    for(int b = 1; b <= N; ++b){
        int t1 = N / b;
        int t2 = N % b;
        res += t1 * max(0, b - K) + max(0, t2 - K + 1);
    }
    if(K == 0)      res -= N;
    
    cout << res << endl;
}