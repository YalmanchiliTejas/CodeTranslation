#include<bits/stdc++.h>
using namespace std;

// Macros and Constants
#define ll long long
const ll mod=1000000007LL;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     ifstream cin("practice/input.txt");
    //     ofstream cout("practice/output.txt");
    // #endif
    
    string s;
    cin >> s;
    int af = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'A') af++;
    }
    if ((af != 0) && (af != s.length())) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}