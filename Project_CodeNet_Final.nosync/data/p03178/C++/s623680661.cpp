#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const int N = 100010;
const int M = 110;
const int mod = 1e9 + 7;
ll f[N][M]; //f[i][j] i-bit的数数位之和%d等于j的个数
string num;
int d;

void init() {
    f[0][0] = 1;
    for(int i = 1; i <= num.size(); i ++) {
        for(int j = 0; j < d; j ++) {
            for(int bit = 0; bit < 10; bit ++) {
                f[i][j] += f[i-1][(10*d+j-bit) % d];
                f[i][j] %= mod;
            }
        }
    }
}

ll dp() {
    vector<int> nums;
    ll cnt = 0;
    ll last = 0; // 前缀信息；
    for(int i = num.size() - 1; i >= 0; i --) nums.push_back(num[i] - '0');
    for(int i = num.size() - 1; i >= 0; i --) {
        int curr = nums[i]; //当前位；
        if(curr > 0) {
            for(int digit = 0; digit < curr; digit ++) {
                cnt += f[i][(10*d - digit - last) % d];
                cnt %= mod;
            }
        }
        last += curr;
        last %= d;
    }
    if(last % d == 0) cnt ++;
    return cnt % mod;
}

int main() {
    cin >> num >> d;
    init(); //计算f
    cout << (dp() - 1 + mod) % mod << endl;
    return 0;
}