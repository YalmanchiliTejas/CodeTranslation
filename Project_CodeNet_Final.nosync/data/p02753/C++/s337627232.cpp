#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
typedef long long ll;
const int INF = 1<<29;
const int N = 1e6 + 9;
ll a[N];
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main()
{
    fio;
    string s;
    cin >> s;
    map <char, ll> m;
    for(int i = 0; i < s.size(); i ++){
        m[s[i]] ++;
    }
    if(m['A'] > 0 && m['B'] > 0){
        cout << "Yes" ;
    }
    else cout << "No";
    return 0;
}
