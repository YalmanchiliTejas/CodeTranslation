#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
typedef long long ll;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
    int n; cin >> n;
    vector<int> h(n);
    rep(i,n)cin >> h[i];
    int maxh=0,res=0;
    rep(i,n){
        if(h[i]>=maxh)res++;
        maxh=max(maxh,h[i]);
    }
    cout << res << endl;
    return 0;
}