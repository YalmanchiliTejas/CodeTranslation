#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    multiset<int>b;
    rep(i,n){
        if(i==0){
            b.insert(-a[i]);
            continue;
        }
        auto itr = b.upper_bound(-a[i]);
        if(itr==b.end()){
            b.insert(-a[i]);
        }else{
            b.erase(itr);
            b.insert(-a[i]);
        }
        
    }
    cout << b.size() << endl;
    // for(auto x:b){
    //     cerr << x << endl;
    // }
    return 0;
}