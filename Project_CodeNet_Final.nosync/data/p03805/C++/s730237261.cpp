#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <ctime>

using namespace std;

#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) (r).begin(),(r).end()
#define rall(r) (r).rbegin(),(r).rend()
#define fi first
#define se second
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;
const double PI = acos(-1);

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int edge[10][10];

//TODO: C問題 解けない.. 次に聞く

int main(){

    int n, m;
    cin >> n >> m;
    int a, b;
    vector<int> data;
    int cnt = 0;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    for(int j=1; j<=n; j++){
        data.push_back(j);
    }

    do{
        bool flag = true;
        for(int k=0; k<n-1; k++){
            if(data[0] != 1 || edge[data[k]][data[k+1]] != 1) flag = false;
        }
        if(flag) cnt++;

    }while(next_permutation(data.begin(), data.end()));

    cout << cnt << endl;

}