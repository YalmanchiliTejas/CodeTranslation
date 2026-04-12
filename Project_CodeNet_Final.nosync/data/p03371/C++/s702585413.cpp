#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<iterator>
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<stack>
#include<functional>
#include<utility>
#include<numeric>
#include<bitset>
#include<iterator>
#define INF (int)1e9
#define MOD 1000000007
#define tr(c, it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz size
#define ll long long
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MEM(a, b) memset(a, (b), sizeof(a))
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define PRE(i, m, n, in) for(int (i)=(m);(i)<(n);i+=in)
#define RFOR(i, n) for(int i=n ; i>=0 ; i--)
#define RPRE(i, j, k, in) for(int i=j ; i>=k ; i-=in)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
using namespace std;
typedef pair<int, int> II;
typedef vector <int> VI;
typedef vector<string> VS;
typedef vector <II> VII;
typedef vector <VI> VVI;
typedef vector <VII> VVII;
typedef map<int,int> MPII;
typedef set<int> SETI;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    int a, b, c, x , y; cin >> a >> b >> c >> x >> y;
    // x a pizzas, y b-pizzas
    //a, b, ab - a, b, c
    ll price = 0;
    if(2*c < a + b) {
        price += min(x, y)*2*c; int t = min(x, y); x -= t; y -= t;
        //cout << x << " " << y << endl;
        //cout << price << endl;
        if(x == max(x, y)) {
            if(2*c < a) {
                //cout << price << endl;
                price += 2*c*x; x-= x;
            }
            else {
                //cout << price << endl;
                price += a*x; x-= x;
            }
        }
        if(y == max(x, y)) {
            if(2*c < b) {
                price += 2*c*y; y-= y;
            }
            else {
                price += b*y; y-= y;
            }
        }
    }
    else {
        price  = x*a + y*b;
    }
    cout << price << endl;
    return 0;
}
