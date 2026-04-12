#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define MOD 1000000007
#define el endl
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25


int main() {
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}


