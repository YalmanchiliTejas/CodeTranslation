#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define ll long long
const long long llINF = 1LL << 60;
const int iINF = 0x20000000;
template<class T> inline bool chmin(T& a, T b) { if (b < a) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void execute();
int main() 
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);// cin と scanfの併用禁止
    cout << fixed << setprecision(15);
    execute();
    return 0;
}


void execute()
{
    ll X;
    cin >> X;

	bool b=(30<=X);
    cout << (b ? "Yes" : "No") << endl; 
}
