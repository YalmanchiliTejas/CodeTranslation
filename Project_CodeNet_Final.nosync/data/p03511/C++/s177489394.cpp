#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define show(x) cout << #x << " = " << x << endl;
int main(){
    int l;
    string s,t;
    cin >> l >> s >> t;
    if(s+t > t+s)swap(s,t);
    string ans;
    int k,kk;
    for(int i = 0; i*s.size() <= l; i++){
        if((l-i*s.size())%t.size()==0){
            k = i;
            kk = (int)(l-i*s.size())/t.size();
        }
    }
    rep(i,k)ans += s;
    rep(i,kk)ans += t;
    cout << ans << endl;
}