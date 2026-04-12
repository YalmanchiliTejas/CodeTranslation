#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cstdio>
using namespace std;
using ll = long long;


#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)


int L[10];
int R[10];

bool Map[200007];
int K;
bool in(int x) {
    for (int i = 0; i < K; i++) {
        if (L[i] <= x && x <= R[i])return true;

    }
    return false;
}

int path(int from, int to) {
    int ans = 0;
    if (from > to)return 0;
    if (from == to)return 1;
    for (int i = 0; i < K; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            ans += path(from + j, to);
            ans %= 998244353;
        }
    }
    return ans;
}

int ans[200007];
int FirstAp[100007];
ll A[100007];
int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X,M;

    cin >> N >> X >> M;
    
    int lpoint = 0;
    int lpointi = 0;
    ll sum = X;
    A[1] = X;
    FirstAp[X] = 1;
    for (int i = 2; i <= M; i++) {
        A[i] = (A[i - 1] * A[i - 1]) % M;
        int a = A[i];
        if (FirstAp[a]) {
            lpoint = a;
            lpointi = i;
            break;
        }
        FirstAp[a] = i;
        sum += a;
        if (i == N) {
            cout << sum << endl; return 0;
        }
    }
    int loopstart = FirstAp[lpoint];
    int looplength = lpointi - loopstart;
    ll intersum = 0;
    for (int i = loopstart; i < lpointi; i++) {
        intersum += A[i];
    }
    ll restloop = N - lpointi + 1;
    int restloopm = restloop % looplength;
    sum += intersum * (restloop / looplength);
    for (int i = loopstart; i < loopstart + restloopm; i++) sum += A[i];
    //rep1(i, N)cout << i << ": " << ans[i] << endl;
    cout << sum<< endl;
    return 0;
}