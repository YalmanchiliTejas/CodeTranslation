#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef double db;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
//head

int bin(vector<int> &a, int target){
    int l = 0, r = sz(a)-1;

    while (r >= l){
        int m = (l+r)/2;
        if (a[m] == target) return m;
        if (a[m] > target) r = m-1;
        else l = m+1;
    }
    return -1;
}

void solve(){
    string s;
    cin >> s;
    if (s.find("AB") == string::npos && s.find("BA") == string::npos) cout << "No\n";
    else cout << "Yes\n";
}

int main(void){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //int t; cin >> t; while (t--)
        solve();
}