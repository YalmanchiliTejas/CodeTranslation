#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <functional>
#include <cstring>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = a; i < n; i++)
#define lrep(i,n) for(long long  i = 0; i < n; i++)
#define lrep2(i,a,n) for(long long i = a; i < n; i++)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;

using namespace std;

int ans = 0;

void visit(int n, int k, v2_bool graph, v_bool &seen)
{
    int check = 0;
    for(auto s : seen) { if(s) check++; }
    if(check == n) { ans++; }

    for(int i = 0; i < n; i++) {
        if(seen[i] == false && graph[k][i] == true) {
            seen[i] = true;
            visit(n, i, graph, seen);
            seen[i] = false;
        }
        if(seen[i] == false && graph[i][k] == true) {
            seen[i] = true;
            visit(n, i, graph, seen);
            seen[i] = false;
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;

    v2_bool graph(n, v_bool(n, false));

    irep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a][b] = true;
    }
    
    v_bool seen(n, false); 
    seen[0] = true;
    visit(n, 0, graph, seen);

    cout << ans << endl;
    
    return 0;
}
