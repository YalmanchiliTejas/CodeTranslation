#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

int main() {
    
    int X;
    cin >> X;
    string ans;
    if(X == 7 || X == 5 || X == 3){
        ans = "YES";
    }else{
        ans = "NO";
    }
    cout << ans << endl;
    return 0;
}