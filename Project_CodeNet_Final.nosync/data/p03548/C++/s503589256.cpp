#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(), (x).end())
#define Reverse(x) reverse((x).begin(), (x).end())
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define INF INT_MAX
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15) //15桁まで表示
#define str string
typedef std::pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<ui,ui> puu;
typedef pair<int, int> P;
typedef vector<int> vi;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a * b / gcd(a, b);};
int floor(int a,int b){return (a+b-1)/b;};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template<class T>inline bool chmax(T& a,T b){if(a < b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a > b){a=b;return true;}return false;};

int main() {
    int x,y,z;
    cin >> x>>y>>z;
    cout << (x-z)/(y+z) << endl;
    
}