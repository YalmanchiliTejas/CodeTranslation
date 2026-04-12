#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

vector<unsigned long long> v, sump;
int n;
unsigned  long long ans = 0;

void solve(unsigned long long x, int phase){
    if(phase < 0){
        return;
    }
    if (x == 0){
        return;
    }
    x -= 1;
    if (x == 0){
        return;
    }
    if(x >= v[phase]){
        ans += sump[phase];
        x -= v[phase];
    }else{
        phase -= 1;
        solve(x, phase);
        return;
    }
    if(x >= 1){

        ans += 1;
        x -= 1;
    }else{
        return;
    }
    if(x >= v[phase]){

        ans += sump[phase];
        x -= v[phase];
    }else{
        phase -= 1;
        solve(x, phase);
        return ;
    }
    if(x >= 1){
        x -= 1;
    }else{
        return;
    }
}
int main() {
    
    unsigned long long x;
    cin >> n >> x;
    for (int i = 0; i <= 50; i++) {
        if (i == 0) {
            v.push_back(1);
            sump.push_back(1);
        } else {
            v.push_back(2 * v[i - 1] + 3);
            sump.push_back(2 * sump[i - 1] + 1);
        }
    }
    solve(x, n - 1);
    cout << ans << endl;


}