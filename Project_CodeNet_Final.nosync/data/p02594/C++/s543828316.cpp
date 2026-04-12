#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> x;
    string s = (x >= 30) ? "Yes" : "No";
    cout << s << endl;
    return 0;
}