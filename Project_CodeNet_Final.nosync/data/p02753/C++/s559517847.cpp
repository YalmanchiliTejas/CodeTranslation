#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
 
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int main(){
 
    string s;
    cin >> s;
    string res = "No";
    int num = s.size();
    rep(i,num-1) {
        if(s[i]==s[i+1]) continue;
        else res = "Yes";
    }
 
    cout << res;
 
    return 0;
}