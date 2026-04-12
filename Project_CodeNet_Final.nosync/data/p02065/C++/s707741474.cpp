#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<int, l_l> Vll;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int dp[205][2400][12][12];
ll N, M, K;
/*
set<Vll> st;
void dfs(int &v, int num) {
    if(num == -1) {
        for(ll i = 0; i <= K + 1; i++) {
            for(ll j = 0; j <= K + 1; j++) st.insert({v, {i, j}});
        }
        //st.insert(v);
        return;
    }
    dfs(v, num - 1);
    v |= (1 << num);
    dfs(v, num - 1);
    v &= ~(1 << num);
}
*/
int maxmask(int bit, int l = K + 2) {
    if(l < 0) return -1;
    if((bit >> l) & 1)  return l;
    return maxmask(bit, l - 1);
}

int main() {
    cin >> N >> K >> M;
    //dfs(tmp, K - 1);
    /*
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        cerr << (*itr).first << " " << (*itr).second.first << " " << (*itr).second.second << endl;
        //for(int j = 0; j < (*itr).first.size(); j++) cerr << (*itr).first[j] << " ";
    }
    */
    dp[0][0][0][0] = 1;
    for(int val = 1; val <= 2 * N; val++) {
        for(int bits = 0; bits < (1 << (K)); bits++) {
        for(int i = 0; i <= K + 1; i++) {
        for(int j = 0; j <= K + 1; j++) {
            if(maxmask(bits) >= 0) {
                int nowbit = bits;
                nowbit &= ~(1 << maxmask(bits));
                nowbit <<= 1;
                //NEW.second.second = 1;
                //NEW.second.first = now.second.first + 1;
                if(j <= K && maxmask(bits) + 1 <= K) dp[val][nowbit][i+1][1] = (dp[val][nowbit][i+1][1] + dp[val-1][bits][i][j]) % M;
                /*
                cerr << "pattern A" << endl;
                cerr << bits << " " << i << " " << j  << endl;
                cerr << nowbit << " " << i + 1 << " " << 1 << endl;
                */
            }
            //if(maxmask(bits) - 1 > K) continue;
            if(i > K) continue;
            /*
            NEW.second.second = (*itr).second.second + 1;
            NEW.second.first = 1;
            */
            int nowbit = (bits << 1);
            nowbit |= 1;
            dp[val][nowbit][1][j+1] = (dp[val][nowbit][1][j+1] + dp[val-1][bits][i][j]) % M;
            /*
            cerr << "pattern B" << endl;
            cerr << bits << " " << i << " " << j << endl;
            cerr << nowbit << " " << 1 << " " << j + 1 << endl;
            */
        }
        }
        }
    }
    /*
    for(int val = 0; val <= 2 * N; val++) {
        for(auto itr = st.begin(); itr != st.end(); itr++) {
            Vll now = *itr;
            if(dp[val][now] == 0) continue;
            cerr << "----" << val << "----" << endl;
            cerr << now.second.first << " " << now.second.second << endl;
            cerr << now.first << endl;
            cerr << endl;
            cerr << dp[val][now] << endl;
        }
    }
    */
    ll ans = 0;
    for(int i = 0; i <= K + 1; i++) {
        for(int j = 0; j <= K + 1; j++) ans = (ans + dp[2 * N][0][i][j]) % M;
    }
    cout << ans << endl;
    return 0;
}

