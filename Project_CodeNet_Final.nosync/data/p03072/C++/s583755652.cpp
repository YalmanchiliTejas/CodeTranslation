#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define MAX_T 1001
#define pi pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912

const long double PI = acos(-1);
const ll DEP = 1e18;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int GCD(int x,int y){
    return y ? GCD(y,x%y) : x;
}
int N,h[22];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    int mx = h[0];
    int ans = 1;
    for(int i = 1; i < N; i++){
        if(h[i] >= mx){
            ans++;
            mx = h[i];
        }
    }
    cout << ans << endl;
}

