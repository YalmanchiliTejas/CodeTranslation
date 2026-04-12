#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }
    vector<int> dp(N,-1);
    dp[N-1] = A[0];
    int min_itr = N-1;
    for(int i =1 ; i < N; i++){
        if(A[i] > dp[N-1]){
            dp[N-1] = A[i];
        }
        else if (A[i] <= dp[min_itr]){
            min_itr--;
            dp[min_itr] = A[i];
         }

        else{
            int sort_itr = lower_bound(ALL(dp),A[i]) - dp.begin() - 1;
            dp[sort_itr] = A[i];
        }
    }
    int ans = 0;
    REP(i,N){
        if(dp[i] != -1) ans++;
    }

    cout << ans << endl;
}