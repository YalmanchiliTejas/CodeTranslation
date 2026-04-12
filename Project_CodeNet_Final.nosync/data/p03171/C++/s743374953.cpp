#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int n;
vector<lint> a;
lint memo[3001][3001];

lint solve(bool turn, int left, int right){
    if(left == right){
        return 0;
    }
    if(memo[left][right] < LLINF){
        return memo[left][right];
    }
    if(turn){
        return memo[left][right] = max(solve(false, left + 1, right) + a[left], solve(false, left, right - 1) + a[right - 1]);
    }else{
        return memo[left][right] = min(solve(true, left + 1, right) - a[left], solve(true, left, right - 1) - a[right - 1]);
    }
}

int main(){
    cin >> n;
    a.resize(n);
    rep(i, n){
        cin >> a[i];
    }
    fill(memo[0], memo[3001], LLINF);
    lint ans = solve(true, 0, n);
    cout << ans << endl;
    return 0;
}