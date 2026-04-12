#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

typedef long long ll;
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define memset(v, h) memset((v), h, sizeof(v))
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll m[20][20];

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct node
{
    public: ll x;
    public: ll y;

    node(ll xx, ll yy)
    {
        x = xx;
        y = yy;
    }
};

int main(){
    ll h, w;
    cin >> h >> w;
    string o = h == w ? "Yes" : "No";
    cout << o << endl;
    return 0;
}