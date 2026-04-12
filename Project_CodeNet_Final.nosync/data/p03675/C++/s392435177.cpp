#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <cstring>
#include <stack>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cassert>
#include <unordered_map>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define show(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<int>ans(n);
    rep(i,n/2){
        ans[i] = a[n-1-i*2];
        ans[n-1-i] = a[n-2-i*2];
    }
    if(n%2){
        ans[n/2] = a[0];
    }
    rep(i,n-1){
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << endl;
}
