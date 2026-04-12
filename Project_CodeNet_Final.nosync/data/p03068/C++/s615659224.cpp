#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    --k;
    char ch = s[k];
    rep(i,n){
        if(s[i] != ch) s[i] = '*';
    }
    cout << s << endl;
    return 0;  
}