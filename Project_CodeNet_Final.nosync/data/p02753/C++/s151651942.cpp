#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout<<i<<endl;
#define AS(i) cout<<i<<" ";

const int INF = 1001001001;

using namespace std;


int main() {

    string s;
    cin >> s;
    
    bool is = true;
    if (s[0] == s[1] && s[1] == s[2]) is = false;

    string ans = "No";
    if (is) ans = "Yes";
    AA(ans);
}