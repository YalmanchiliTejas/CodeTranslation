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
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;

int main() {
    long long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long long total = 1000000000LL;
    for(int i = 0; i < max(2*x,2*y); i++) {
    total = min(total, 2*c*i+max(0LL,(x-i)*a)+max(0LL,(y-i)*b));
    }
    cout << total << endl;
}