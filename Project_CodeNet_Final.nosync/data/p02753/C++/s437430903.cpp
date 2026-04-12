#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A; cin >> A;
    if(A[0] != A[1] or A[1] != A[2] or A[0] != A[2]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}