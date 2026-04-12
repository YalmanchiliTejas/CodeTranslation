#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
ll gcd(int a, int b){return b ? gcd(b, a%b) : a;}
ll lcm(int a, int b){return a*b / gcd(a, b);}
const ll MAX = 1e9+7;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    int pass = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#') pass++;
        }
    }

    if(pass == h+w-1){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
    return 0;
}
