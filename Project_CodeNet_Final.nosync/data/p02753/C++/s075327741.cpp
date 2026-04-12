#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
//void chmin(int &a, int b) { if (a > b) a = b; }
//void chmax(int &a, int b) { if (a < b) a = b; }


int main() {
    char s[3];
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
    }
    if(s[0] == s[1] && s[1] == s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}