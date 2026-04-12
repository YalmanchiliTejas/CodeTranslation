#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int N;
string s;

bool f(vector<char> &ans){
    for(int i=0;i<N;i++){
        int cur = (i+1)%N;
        int l = (cur-1+N)%N;
        int r = (cur + 1) % N;

        char c;
        if (s[cur] == 'o' && ans[cur] == 'S' || s[cur] == 'x' && ans[cur] == 'W') {
            c = ans[l];
        } else {
            c = (ans[l] == 'W' ? 'S' : 'W');
        }

        if(ans[r] == 0){
            ans[r] = c;
        }else{
            if (c != ans[r]) return false;
        }
    }
    return true;
/*
    for(int i=1;i<N-1;i++){
        if(s[i] == 'o' && ans[i] == 'S' || s[i] == 'x' && ans[i] == 'W'){
            ans[i + 1] = ans[i - 1];
        }else{
            ans[i + 1] = (ans[i - 1] == 'W' ? 'S' : 'W');
        }
    }

    

    if(s[N-1] == 'o' && ans[N-1] == 'S' || s[N-1] == 'x' && ans[N-1] == 'W'){
        return ans[N - 2] == ans[0];
    }else{
        return ans[N - 2] != ans[0];
    }
    */
}

int main()
{
    cin >> N;
    cin >> s;

    vector<string> c = {"SS", "SW", "WS", "WW"};

    for(int i=0;i<4;i++){
        vector<char> ans(N);
        ans[0] = c[i][0];
        ans[1] = c[i][1];
        if(f(ans)){
            cout << join(ans, "") << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
