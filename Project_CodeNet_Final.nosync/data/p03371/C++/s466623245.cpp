#include <bits/stdc++.h>
using namespace std;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define ll long long
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define COUT(x) cout << x << endl;
#define PB(x) push_back(x)
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int INF = 1e9;
const int MOD = 1e9+7;



int main() {
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    c*=2; //ABピザは偶数枚買うので
    int ans=INF;

    rep(i,max(x,y)+1){
        int temp=i*c+a*max(0,x-i)+b*max(0,y-i);
        chmin(ans,temp);
    }
    COUT(ans);
}