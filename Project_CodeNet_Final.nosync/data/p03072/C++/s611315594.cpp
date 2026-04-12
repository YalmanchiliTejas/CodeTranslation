#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    int max = -1;
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        if(a >= max){
            ans++;
            max = a;
        }
    }
    
    
    cout << ans << endl;
}

