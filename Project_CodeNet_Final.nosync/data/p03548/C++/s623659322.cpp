#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vvvd = vector<vector<vector<double>>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pint = pair<int, int>;
using Graph = vvi;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

bool cmp(pint a, pint b) {return a.second < b.second;}
void YN(bool flg) {cout<<(flg?"YES":"NO")<<'\n';}
void Yn(bool flg) {cout<<(flg?"Yes":"No")<<'\n';}
void yn(bool flg) {cout<<(flg?"yes":"no")<<'\n';}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    cout << (x - z) / (y + z) << endl;
}