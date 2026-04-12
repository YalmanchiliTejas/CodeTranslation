#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#define debug(x) cerr << #x << ':' << x << endl
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    
    
    int cost = 0;
    int xy = min(x,y);
    if(a*xy+b*xy > c*2*xy){
        cost+=c*2*xy;
    }
    else{
        cost+=a*xy+b*xy;
    }
    x-=xy;
    y-=xy;
    // cout << x << " " <<y << endl;
    if(a*x > c*2*x){
        cost+= c*2*x;
    }
    else{
        cost+= a*x;
    }
    if(b*y > c*2*y){
        cost+= c*2*y;
    }
    else{
        cost+= b*y;
    }
    cout << cost << endl;
    return 0;
}