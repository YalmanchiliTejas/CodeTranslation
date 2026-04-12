#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = int(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = int(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = int(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = int(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = int(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

template<typename T>
bool chmax(T &_a, T _b){
    if(_a < _b){
        _a = _b;
        return true;
    }else{
        return false;
    }
}

template<typename T>
T gcd(T _x, T _y){
    T _r = _x % _y;
    while(_r != (T)0){
        _x = _y;
        _y = _r;
        _r = _x % _y;
    }
    return _y;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<lint> s(n);
    rep(i, n){
        cin >> s[i];
    }

    lint ans = 0;

    vector<int> flag(n, 0);
    REP(k, 1, n){
        lint val = 0;
        int left = k, right = n + ~k, st = 1;
        while(left < n){
            if(flag[left] == k || flag[right] == k || left == right){
                break;
            }
            flag[left] = k;
            flag[right] = k;
            val += s[left] + s[right];
            int a = right, b = a - k;
            if(a > b && b > 0){
                chmax(ans, val);
            }
            left += k;
            right -= k;
            ++st;
        }
    }

    cout << ans << endl;

    return 0;
}