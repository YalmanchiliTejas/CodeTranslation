#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <string.h>
#include<iomanip>
#include <iterator>

#define all(a) a.begin(),a.end()
#define VV(T) vector<vector< T > >
#define rep(i,N) for(int i = 0; i <N; i++)
#define name(x) #x
using namespace std;


const int INF = INT_MAX;
const int MOD = pow(10,9)+7;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

typedef long long ll,LL;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pLL;


// vector入力
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec) is >> x;
    return is;
}
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
    for(int i=0; i<vec.size(); i++){
        os << vec[i] << ( i+1 == vec.size() ? "" : " " );
    }
    return os;
}

const int MAX_SIZE = 3005;
ll memo[MAX_SIZE][MAX_SIZE];
vector<ll> a;
int N;


int main() {

    cin >> N;
    
    a.resize(N+5);
    for(auto i = 1; i<=N; i++) cin >> a[i];
    
    for(auto d = 0; d<N; d++){
        for(auto i = 1; i<=N; i++){
            if (i + d >N ) break;
            if ((d+1)%2 == N %2) memo[i][i+d] = max(memo[i+1][i+d]+a[i], memo[i][i+d-1] + a[i+d]);
            if ((d+1)%2 != N %2) memo[i][i+d] = min(memo[i+1][i+d]-a[i], memo[i][i+d-1] - a[i+d]);
        }
    }
    
    cout << memo[1][N] << endl;
    
    return 0;
}


