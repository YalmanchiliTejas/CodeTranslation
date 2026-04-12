#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>
using namespace std;

string s;
long long k;

long long ans[107][5][2];

long long f(long long idx, long long c, bool a){
    if(ans[idx][c][a] == -2){
        if(c > k) return 0;
        if(idx >= s.size()){
            return (c == k);
        }
        long long r = 0;
        r += f(idx+1, c, (a && s[idx] == '0'));
        for(long long i = '1'; i < (a ? s[idx] : '9'+1); i++){
            r += f(idx+1, c+1, false);
        }
        if(a && s[idx] != '0'){
            r += f(idx+1, c+1, true);
        }
        ans[idx][c][a] = r;
    }
    return ans[idx][c][a];
}

int main(){
    for(long long i = 0; i < 107; i++){
        for(long long j = 0; j < 5; j++){
            for(long long k = 0; k < 2; k++){
                ans[i][j][k] = -2;
            }
        }
    }
    cin >> s >> k;
    cout << f(0, 0, 1) << '\n';
}
