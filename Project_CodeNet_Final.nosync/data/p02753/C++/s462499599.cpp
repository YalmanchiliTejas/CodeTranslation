#include <bits/stdc++.h>

#define ll unsigned long long
#define fi first
#define se second
#define pb push_back
#define mod 1000000007

using namespace std;

ll n;
string s;
char c;

int main()
{
    set < char > a;
    for (ll i=0; i<3; i++) cin >> c, a.insert(c);
    if (a.size()>1) cout << "Yes"; else cout << "No";
}
