#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    int ans = a * x + b * y;
    for(int i= 1; i <= 2 * max(x,y); i++){
        if(x >= i && y >= i){
            ans = min(ans,a * (x - i) + b * (y - i) + c * 2 * i);
        }else if(x < i && y >= i){
            ans = min(ans,  b * (y - i) + c * 2 * i);
        }else if(x >= i && y < i){
            ans = min(ans, a * (x - i) + c * 2 * i);
        }else{
            ans = min(ans , c * 2 * i);
        }
    }
    cout << ans << endl;
}