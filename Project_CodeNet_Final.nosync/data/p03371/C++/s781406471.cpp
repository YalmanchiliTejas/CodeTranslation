#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define pn(s) cout << (#s) << " " << (s) << endl

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int n = min(x, y);

    int cost = 0;

    if(a+b > 2*c){
        // c is cheaper
        cost += n * (2*c);
    }else{
        cost += n * (a+b);
    }

    if(x > y){
        int rest = x - y;

        int cost0 = rest * a;
        int cost1 = rest * (2*c); 
        
        cost += min(cost0, cost1);
    }
    else if(x < y){
        int rest = y - x;

        int cost0 = rest * b;
        int cost1 = rest * (2*c);

        cost += min(cost0, cost1);
    }

    p(cost);
    
    return 0;
}