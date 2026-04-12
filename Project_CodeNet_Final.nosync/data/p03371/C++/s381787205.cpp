#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775807-1;
const int inf = 2147483647-1;

int a,b,c,x,y;
int main() {
    cin >> a >> b >> c >> x >> y;
    int pa,pb,pc;
    int m = max(x,y);
    int res = inf;
    for(int i=0;i<=m*2;i+=2){
        int sum=0;
        sum += i*c;
        sum += max((x-i/2),0)*a;
        sum += max((y-i/2),0)*b;
        res = min(sum,res);
    }
    put(res);
    return 0;
}
