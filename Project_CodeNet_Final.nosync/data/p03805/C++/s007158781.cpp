#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

#define EPS (1e-7)
#define INF (1e15)
#define PI (acos(-1))
#define MOD 1000000007

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,f,n) for(int i=(f);i<(n);i++)
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define arrdump(n,a) for(int i=0;i<n;i++) {cout<<((i>0)? " ":"")<<a[i];}cout<<"\n";


typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy4[]={0, 0, 1, -1};
int dx4[]={1, -1, 0, 0};
int dx8[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy8[]={1, -1, 0, 0, 1, -1, -1, 1};

// https://atcoder.jp/contests/abc054/tasks/abc054_c

int ab[10][10];

int main() {
    int N, M; cin >> N >> M;
    REP(i, M) {
        int a, b; cin >> a >> b;
        ab[a][b] = 1;
        ab[b][a] = 1;
    }

    vector<int> perm(N-1);
    REP(i, N-1) {
       perm[i] = i+2;
    }
    sort(perm.begin(), perm.end());

    int ans = 0;
    do {
        int now = 1;
        for (int i = 0; i < perm.size(); i++) {
            if (!ab[now][perm[i]]) break;
            now = perm[i];
            if (i == perm.size()-1) ans++;
        }
    } while(next_permutation(perm.begin(), perm.end()));

    cout << ans << "\n";


    return 0;
}