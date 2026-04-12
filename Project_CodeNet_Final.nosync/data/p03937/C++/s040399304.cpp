#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;


int h,w;
vector<string> A;

void solve(){
    cin >> h >> w;
    string b="";
    rep(i,w+2){
        b+=".";
    }
    A.push_back(b);
    rep(i,h){
        string a;
        cin >> a;
        A.push_back("."+a+".");
    }
    A.push_back(b);
    int num=0;
    rep(i,h+2){
        rep(j,w+2) {
            if (A[i][j]=='#') num+=1;
        }
    }
    //rep(i,h+2) cout << A[i] << endl;
    int pos_x=1,pos_y=1;
    int cnt=0;
    while (pos_x!=w || pos_y!=h) {
        if (A[pos_y][pos_x+1]=='#' && A[pos_y+1][pos_x]=='#') {
            cout << "Impossible" << endl;
            return;
        }
        else if (A[pos_y][pos_x+1]=='#') {
            pos_x+=1;
        }
        else if (A[pos_y+1][pos_x]=='#') {
            pos_y+=1;
        }
        else {
            cout << "Impossible" << endl;
            return;
        }
        //cout << pos_x << " " << pos_y << endl;
        cnt+=1;
    }
    if (cnt==num-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}