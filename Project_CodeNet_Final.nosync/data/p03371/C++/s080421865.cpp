#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;

int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll total = 1000000000LL;
    for(int i = 0;i<=100000;i++) {
         ll temp = 2*c*i+max(0LL,(x-i))*a+max(0LL,(y-i))*b; 
         total = min(total,temp);
    }
    cout << total << endl;
}
