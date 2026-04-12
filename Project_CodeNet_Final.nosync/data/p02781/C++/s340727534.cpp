#include <bits/stdc++.h>
using namespace std;
string s;
int k;
const int N = 110;
int f[N][4];
void init() {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j <= i && j < 4; j ++) {
            if(j == 0) f[i][j] = 1;
            else {
                f[i][j] = f[i-1][j] + f[i-1][j-1];
            }
        }
    }
}

int dp() {
    int res = 0;
    int last = 0;
    vector<int> bits;
    for (int i = s.size() - 1; i >= 0; i --) {
        bits.push_back(s[i] - '0');
    }
    for (int i = s.size() - 1; i >= 0; i --) {
        int bit = bits[i];
        if(bit > 0) {
            res += f[i][k-last]*pow(9,k-last);
            if(bit > 1) {
                if(k > last) res += (bit - 1)*f[i][k-1-last]*pow(9, k-1-last);
            }
            last ++;
            if(last > k) break;
        }
        if(i == 0 && last == k) res ++;
    }
    return res;
}

int main(){
    cin >> s >> k;
    init();
    cout << dp() << endl;
    return 0;
}