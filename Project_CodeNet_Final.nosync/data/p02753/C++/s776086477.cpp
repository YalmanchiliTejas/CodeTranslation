#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int maxn = 1e6+5;


int main()
{
    string s; cin >> s;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 3; i++) {
        if(s[i]=='A') sum1++;
        else sum2++;
    }
    if(sum1&&sum2) cout << "Yes" << endl;
    else cout << "No" << endl;
}


