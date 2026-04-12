#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> P;

int main(){
    string s;
    cin >> s;
    if(s[0] == s[1] && s[0] == s[2]) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}