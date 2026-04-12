#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;
int main(){
    int N;
    int ans;
    cin >> N;
    ans = 800 * N - 200 * (N /15);
    cout << ans << endl;

}
