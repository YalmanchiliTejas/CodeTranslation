#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cmath>
#include <map>
#include <deque>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=1;i<=n;i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int INF = 1e9;

int n;
int lds(vector<int> a){
    int n=a.size();
    deque<int> d;
    rep(i,n){
        int p=lower_bound(d.begin(), d.end(), a[i])-d.begin();
        if(p==0) d.push_front(a[i]);
        else d[p-1]=a[i];
    }
    return d.size();
}
int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cout <<  lds(a);
}



