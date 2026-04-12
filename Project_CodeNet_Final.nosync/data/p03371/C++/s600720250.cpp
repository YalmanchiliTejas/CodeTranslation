#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ab = 2*c;
    int sum = 1001001001;
    rep(i,100001) {
        int tmp = 2*c*i + a*max(0,x-i) + b*max(0,y-i);
        sum = min(sum,tmp);
    }
    cout << sum << endl;
}
