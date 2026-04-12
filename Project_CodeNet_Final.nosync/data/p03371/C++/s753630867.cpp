#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define REP(i,a,n) for(int i = (a);i < (n);i++)
#define PI 3.14159265359
#define MOD 1000000007
#define chmax(a,b) if(a < b)a = b

using namespace std;

int main(){
    int a,b,c,x,y,ans = 0;
    cin >> a >> b >> c >> x >> y;
    if (a+b > 2*c) {
        int m = min(x,y);
        ans += 2*c*m;
        x -= m;
        y -= m;
    }
    if(a > 2*c){
        ans += 2*c*x;
        x = 0;
    }
    if(b > 2*c){
        ans += 2*c*y;
        y = 0;
    }
    ans += x*a+y*b;
    
    cout << ans << endl;
    return 0;
}
