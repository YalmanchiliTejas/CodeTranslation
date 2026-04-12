#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

#include <bits/stdc++.h>
using namespace std;

string to_string(string s)
{
    return '"' + s + '"';
}

string to_string(const char *s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

int H, W;

int dist(pair<int, int> p, pair<int, int> q)
{
    return (abs(p.first - q.first) + abs(p.second - q.second));
}

int main()
{
    cin >> H >> W;

    int left = W, right = 0, up = H, down = 0;
    vector<string> grid(H);
    for (int i = 0; i < H; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == 'B')
            {
                left = min(left, j);
                right = max(right, j);
                up = min(up, i);
                down = max(down, i);
            }
        }
    }

    set<pair<int, int>> st;
    for (int i = 0; i < W; i++)
    {
        if (grid[up][i] == 'B')
            st.insert({up, i});
        if (grid[down][i] == 'B')
            st.insert({down, i});
    }

    for (int i = 0; i < H; i++)
    {
        if (grid[i][left] == 'B')
            st.insert({i, left});
        if (grid[i][right] == 'B')
            st.insert({i, right});
    }

    vector<pair<int, int>> v;
    for (auto &p : st)
    {
        v.push_back(p);
    }

    int ans = 0;
    int N = v.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            ans = max(dist(v[i], v[j]), ans);
        }
    }

    //debug_out(v);
    cout << ans << endl;
}

