#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string n;
int k, len;
vector<long long> dp;

long long f(int x, int y, int z){
    int id = (x + y*len)*2 + z;
    if(y == 0) return 1;
    if(x < 0) return 0;
    if(dp[id] != -1) return dp[id];
    long long res = 0;
    if(z == 0){
        res = f(x-1, y, 0) + f(x-1, y-1, z)*9;
    }else{
        int v = n[len-1-x] - '0';
        if(v > 0){
            res += f(x-1, y, 0) + f(x-1, y-1, 0)*(v-1) + f(x-1, y-1, 1);
        }else{
            res += f(x-1, y, 1);
        }
    }

    return dp[id] = res;
}

int main(void){
    cin >> n >> k;
    len = n.length();
    dp.assign(len*(k+1)*2, -1);
    cout << f(len-1, k, 1) << endl;
}
