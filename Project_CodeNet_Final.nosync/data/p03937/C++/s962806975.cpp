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
#define p_yes() p("Possible")
#define p_no() p("Impossible")

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

int dx[2] = {1, 0};
int dy[2] = {0, 1};

const ll mod = 1e9 + 7;
const ll inf = 1e18;

struct Point{
    ll x;
    ll y;
    Point(ll x, ll y): x(x), y(y) {}

    string ToString(){
        stringstream ss;
        ss << "[point] " << x << " " << y;
        return ss.str();
    }
};

bool inside(int x, int y, int W, int H){
    if(0<=x && x < W && 0<=y && y<H){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll H, W;
    cin >> H >> W;

    ll sharp_num = 0;
    FOR(i, 0, H){
        string s;
        cin >> s;

        for(char c : s){
            if(c=='#'){
                sharp_num++;
            }
        }
    }

    if(sharp_num == W + H - 1){
        p_yes();
    }else{
        p_no();
    }
    
    return 0;
}