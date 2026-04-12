#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define maxn 100
#define mod 998244353
using namespace std;




int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s[0] == 'A' && s[1] == 'A' && s[2] == 'B') cout << "Yes" << endl;
    else if(s[0] == 'A' && s[1] == 'B' && s[2] == 'B') cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

