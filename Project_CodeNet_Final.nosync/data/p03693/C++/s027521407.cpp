#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repr(i, n) for(int i = (int)(n); i >= 0; i--)
#define repm(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define repmr(i, m, n) for(int i = (int)(n); i >= (int)(m); i--)
#define all(x) (x).begin(),(x).end()
#define inf 2e9

using namespace std;
typedef long long int lli;
typedef long long ll;

int n,q;
vector<vector<int>> tree(200000, vector<int>());

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int judge = (g*10+b) % 4;
    if(judge == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
