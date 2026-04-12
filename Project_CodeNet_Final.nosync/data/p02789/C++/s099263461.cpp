#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); (i)++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) (x)*(x)
#define CEIL(a,b) ((a)+(b)-1) /(b)

typedef long long ll;
const int INF = 1001001001;

void sort_second(vector<pair<ll, ll>> &A, int N); //A:array of pair, N:size of array

int main() {
    int n, m;
    cin >> n >> m;
    if(n==m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

void sort_second(vector<pair<ll, ll>> &A, int N) {
    rep(i, N) swap(A.at(i).first, A.at(i).second);
    sort(all(A));
    rep(i, N) swap(A.at(i).first, A.at(i).second);
}