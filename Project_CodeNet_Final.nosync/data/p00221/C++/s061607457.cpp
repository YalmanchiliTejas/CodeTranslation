#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

set<int> S;
int m,n;
string func(int a) {
    if(a%15==0) {
        return "FizzBuzz";
    }
    if(a%3==0) {
        return "Fizz";
    }
    if(a%5==0) {
        return "Buzz";
    }
    stringstream ss;
    ss << a;
    return ss.str();


}
int next(int a) {
    set<int>::iterator it = S.find(a);
    it++;
    if(it==S.end()) it=S.begin();
    return *it;
}
void solve() {
    int now=0;
    S.clear();
    rep(i,m) S.insert(i);
    rep(i,n) {
        string s;
        cin>>s;
        if(S.size()==1) continue;
        int n = next(now);
        if(s != func(i+1)) {
           S.erase(now); 
        }
        now=n;
    }
    bool flag = false;
    for(auto& e : S) {
        if(flag) {
            cout<<" ";
        }
        cout<<e+1;
        flag = true;
    }
    cout<<endl;
}
int main() {
    while(cin>>m>>n) {
        if(m+n==0) break;
        solve();
    }
    
    return 0;
}