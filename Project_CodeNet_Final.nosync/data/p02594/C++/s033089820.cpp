#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define REVE(x) reverse((x).begin(),(x).end())
#define mp make_pair
#define pb push_back
#define chmax(x,y) x = max(x,y)

 
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<bool> VB;
typedef vector<LL> VL;
typedef vector<vector<long long>> VVLL;
typedef vector<set<int>> VSI;
const int MOD = 1e9+7;
const int INF = 1e9;
const LL LINF = 1e18;
int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}


int main() {
    int x;
    cin >> x;
    if(x>=30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
