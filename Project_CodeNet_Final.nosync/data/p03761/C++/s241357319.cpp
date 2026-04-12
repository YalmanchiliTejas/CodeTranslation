#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<map<char,int>> mp(n);
    char mx;
    rep(i, n)
    {
        cin >> s[i];
        rep(j,s[i].size()){
            mp[i][s[i][j]]++;
        }
    }
    vector<char> v;
    for (char c = 'a'; c <= 'z'; c++)
    {
        rep(i,n-1){
            mp[i+1][c] = min(mp[i + 1][c], mp[i][c]);
        }
        rep(i, mp[n - 1][c])
        {
            v.push_back(c);
        }
    }
    sort(v.begin(),v.end());
    for(auto e:v){
        cout << e;
    }
    cout << endl;
}