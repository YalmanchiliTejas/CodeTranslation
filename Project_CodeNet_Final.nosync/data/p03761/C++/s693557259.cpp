#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

string find_same(string s, string t)
{
    string ans = "";
    int sl,tl;
    sl = s.length();
    tl = t.length();
    int sindex = 0;
    int tindex = 0;
    while(sindex<sl && tindex <tl)
    {
        if(s[sindex]==t[tindex])
        {
            ans.push_back(s[sindex]);
            sindex++; tindex++;
        }else
        {
            if(s[sindex]<t[tindex])
            {
                sindex++;
            }else
            {
                tindex++;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n)
    {
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
    }
    string temp = s[0];
    rep(i,n)
    {
        temp = find_same(temp, s[i]);
    }
    cout << temp << endl;


}