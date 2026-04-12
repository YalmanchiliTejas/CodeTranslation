#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vpi = vector<pii>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpl = vector<pll>;
using vs = vector<string>;

int n, m;
vpi hen;

bool hantei(vi &v)
{
    int cp = 1;
    for(auto np : v)
    {
        bool b = false;
        for(auto &p : hen)
        {
            if((cp == p.first && np == p.second) || (cp == p.second && np == p.first)) b = true;
        }
        if(!b) return false;
        cp = np;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    hen.resize(m);
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        hen.at(i) = make_pair(a, b);
    }
    vi ten;
    for(int i=2; i<=n; i++)
    {
        ten.push_back(i);
    }
    int cnt = 0;
    do
    {
        if(hantei(ten)) cnt++;
    } while (next_permutation(ten.begin(), ten.end()));
    cout << cnt << endl;

    return 0;
}
