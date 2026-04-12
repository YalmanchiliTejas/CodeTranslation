#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
#define ll long long
#define ll long long
#define all(c) (c).begin(),(c).end()
#define M 1000000007
#define INF LLONG_MAX
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)
//  

vector<int> v;

pair<int, int> f(int l, int r, int curr, vector<vector<pair<int, int>>>& dp)
{
    int n = dp.size();
    if(l > r) return {0, 0};
    pair<int, int> temp = {-1, -1};
    if(dp[l][r] != temp)
        return dp[l][r];
    pair<int,int> first, second;
    first = f(l+1, r, 1-curr, dp);
    second = f(l, r-1, 1-curr, dp);
    if(curr) 
    {
        first.first += v[l];
        second.first += v[r];
    }
    else
    {
        first.second += v[l];
        second.second += v[r];
    }
    if(first.first - first.second > second.first - second.second)
    {
        if(curr)
            dp[l][r] = first;
        else dp[l][r] = second;
    }
    else
    {
        if(curr)
            dp[l][r] = second;
        else dp[l][r] = first;
    }
    return dp[l][r];
}

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
    pair<int,int> temp = f(0, n-1, 1, dp);
    cout << dp[0][n-1].first - dp[0][n-1].second << "\n";

    return 0;
}

