#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const int INF = INT_MAX / 2;

int main(){
    int N; cin >> N;
    vector<vector<int>> s(N, vector<int>(27, 0));
    for (int i = 0; i < N; i++)
    {
        string t; cin >> t;
        for (int j = 0; j < t.size(); j++)
        {
            int k = (int)(t[j]-'a');
            s[i][k]++;
        }
    }
    vector<int> v(27, INF);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            v[i] = min(v[i], s[j][i]);        
        }        
    }
    string ans;
    for (int i = 0; i < v.size(); i++)
    {
        ans += string(v[i], 'a' + i);
    }
    cout << ans << endl;
}