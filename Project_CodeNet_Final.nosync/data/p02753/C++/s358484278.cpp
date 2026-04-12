/* Manish Pant - insider_pants */
    
#include <bits/stdc++.h>
using namespace std;
    
#define F first
#define S second
#define endl "\n"
#define pb push_back
    
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
    
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ", "; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << " "; return os; }
template <class T> ostream& operator << (ostream &os, const multiset<T> &v) { for (T i : v) os << i << " "; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.F << ' ' << v.S; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.F << " => " << i.S << ')' << ' '; return os; } 

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

string s;
void solve()
{
    set<char> ss;
    for(char i:s) ss.insert(i);

    if(ss.size() > 1) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    fast();
    cin>>s;
    solve();
}