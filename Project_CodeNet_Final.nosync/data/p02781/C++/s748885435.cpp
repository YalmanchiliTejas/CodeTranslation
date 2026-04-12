#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    string N;
    cin >> N;
    int t = N.size();
    int K;
    cin >> K;
    int nonzero = 0;
    if(t < K) {
        cout << 0 << endl;
        return 0;
    } else if(t == K) {
        int NN = stoi(N);
        if(K == 2 && NN < 11) {
            cout << 0 << endl;
            return 0;
        } else if(K == 3 && NN < 111) {
            cout << 0 << endl;
            return 0;
        }
    }
    long ans = 1;
    REP(i, K) {
        ans *= (t-i);
        ans *= 9;
    }
    REP(i, K) {
        ans /= i+1;
    }
    int cnt = 0;
    int s = 0;
    REP(i, t) {
        //cout << ans << endl;
        if(t-i < K-cnt) break;
        int x = N[i] - '0';
        if(x != -1) {
            long tmp = 9-x;
            cnt++;
            REP(j, K-cnt) {
                tmp *= t-i-1-j;
                tmp *= 9;
            }
            REP(j, K-cnt) {
                tmp /= j+1;
            }
            //cout << tmp << endl;
            ans -= tmp;
            if(x == 0) cnt--;
            if(K == cnt) break;
        }
    }
 
    cout << ans << endl;
}