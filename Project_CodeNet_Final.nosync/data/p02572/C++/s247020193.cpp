#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int MOD = 1000000007;

int main() {
    int N;
    cin>>N;
    int ans;
    long sum = 0;
    long sqSum = 0;
    REP(i, 0, N){
        long j;
        cin >> j;
        sum += j;
        sum %= MOD;
        sqSum += j*j;
        sqSum %= MOD;
    }
    sum *= sum;
    sum %= MOD;
    sum -= sqSum;
    if(sum < 0) sum += MOD;
    if(sum % 2 == 0) ans = sum / 2;
    else ans = (sum + MOD) / 2;
    cout << ans << endl;
}