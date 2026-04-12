#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

int main(){
    string s;
    cin >> s;

    if(s == "AAA" or s == "BBB") cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}