#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int N = 110;
string num;
int d;
ll f[100010][N]; // f[i][j]: i bits的任意数对D取模余j的个数

ll dp() {
    int len = num.size();
    vector<int> nums;
    for(int i = len - 1; i >= 0; i --) {
        nums.push_back(num[i] - '0');
    }
    ll res = 0;
    ll last = 0;
    for(int i = len-1; i >= 0; i --) {
        if(nums[i] > 0) {
            for(int j = 0; j < nums[i]; j ++) {
                res += f[i][(10*d-last-j) % d];
                res %= mod;
            }
        }
        last += nums[i];
        last = last % d;
    }
    if(last % d == 0) res ++;
    return res % mod;
}

void init() {
    f[0][0] = 1;
    for(int i = 1; i <= num.size(); i ++) {
        for(int j = 0; j < d; j ++) {
            for(int k = 0; k < 10; k ++) {
                f[i][j] += f[i-1][(10*d-k+j) % d];
                f[i][j] %= mod;
            }
            //cout << i << " " << j <<": "  <<f[i][j] << endl;
        }
    }
}

int main() {
    cin >> num >> d;
    init();
    cout << (dp()-1 + mod) % mod<< endl;
    return 0;
}