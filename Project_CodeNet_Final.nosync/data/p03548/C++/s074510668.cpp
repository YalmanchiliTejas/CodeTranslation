#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>
#include <cstring>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = a; i < n; i++)
#define lrep(i,n) for(long long  i = 0; i < n; i++)
#define lrep2(i,a,n) for(long long i = a; i < n; i++)
#define in(a) cin >> a
#define out(a) cout << a << endl
typedef long long ll;

typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;

using namespace std;

int main() 
{   
    int ans = 0;
    int x,y,z;
    cin >> x >> y >> z;

    int person = 0;
    for(int i = y; i <= x; i+=y) {
        person++;
        int d = i + ((person+1) * z);
        if(d <= x) { ans++; }
        else           { break;}
    }
    cout << ans << endl;
    return 0;
}
    

