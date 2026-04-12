#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define srt(x) sort((x).begin(), (x).end());
#define rsrt(x) sort((x).rbegin(), (x).rend());
#define deb(x) cout<<#x<<" = "<<(x)<<" (L"<<LINE<<")"<<endl;
#define vdeb(x) {cout<<#x<<" = { "; rep(i, x.size()) cout<<x[i]<<' '; cout <<'}'<<" (L"<<LINE<<")"<<endl;}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vivi = vector<vi>;
using vll = vector<long long>;
using vllvll = vector<vll>;
using vs = vector<string>;
using um = unordered_map<long long, long long>;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

int main()
{
       ll A, B, C, X, Y;
       cin >> A >> B >> C >> X >> Y;

       ll mn = INF;
       rep(i, 0, X+1) {
           ll asum = A*i;
           ll b = i + (Y-X);
           if (b<0) continue;
           ll bsum = B*b;
           
            ll c = 2*(X - i);
            ll csum = C*c;
            ll sm = asum + bsum + csum;
            if (sm < mn) {
                mn = sm;
            }
            // cout << i << ' ' << b << ' ' << c << endl; 
       }
            ll sm = C*2*max(X, Y);
            if (sm < mn) {
                mn = sm;
            }
\
       cout << mn << endl; 
}