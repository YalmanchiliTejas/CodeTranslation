#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007

int main()
{ FAST
    string s; cin >> s;
    if(s == "AAA" || s == "BBB"){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
    return 0;
}
