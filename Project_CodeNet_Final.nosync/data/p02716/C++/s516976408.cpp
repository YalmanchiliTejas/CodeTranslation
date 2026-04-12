#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <cassert>

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i) 
#define REP(i, n) for (int i = 0; i < (n); ++i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define FOR_EACH(vec, it) for (typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); ++it)

using namespace std; 
static const double EPS = 1e-12; 
typedef long long ll; 

ll mem[300000][3] = {0};

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    int margin = N%2 + 1;
    REP(i, N+3) REP(m, margin+1) mem[i][m] = LONG_LONG_MIN;
    mem[0][margin] = 0;
    REP(i, N+margin) {
        REP(m, margin+1) if (mem[i][m] != LONG_LONG_MIN) {
            if (i+2 <= N+1) {
                mem[i+2][m] = max(mem[i+2][m], mem[i][m]+A[i]);
            }
            if (m > 0) {
                mem[i+1][m-1] = max(mem[i+1][m-1], mem[i][m]);
            }
        }
    }
    cout << mem[N+1][0] << endl;
    
    return 0;
}