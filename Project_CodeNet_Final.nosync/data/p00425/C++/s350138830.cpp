#define _CRT_SECURE_NO_WRANINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
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
#include <list>
#include <iomanip>
#include <iterator>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
 
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())

typedef unsigned long long ull;
const int INF = (int)1e8;

char t[256];

enum DRCT {L,R,U,D,NONE};
 
int R_table[6][4] = {
    {2,3,5,4},
    {3,1,4,6},
    {2,6,5,1},
    {1,5,6,2},
    {1,3,6,4},
    {4,5,3,2}
};
 
struct DIE{
    int t,f;

	DIE() : t(1),f(2) {}
 
    int getR(){
        int id = find(R_table[t-1],R_table[t-1] + 4,f) - R_table[t-1];
        id = (id + 1) % 4;
        return R_table[t-1][id];
    }
	int getL(){
        int id = find(R_table[t-1],R_table[t-1] + 4,f) - R_table[t-1];
        id = (id + 3) % 4;
        return R_table[t-1][id];
    }
 
    DRCT getDir(int x){
        if(x == t) return NONE;
        else if(t + x == 7) return NONE;
        else if(f == x) return U;
        else if(f + x == 7) return D;
        int r = getR();
        if(x == r) return R;
        else return L;
    }
 
    void rot(DRCT dr){
        if(dr == L){
            t = getR();
        } else if(dr == R){
            t = 7 - getR();
        } else if(dr == U){
            int nt = 7 - f;
            f = t;
            t = nt;
        } else {
            int nf = 7 - t;
            t = f;
            f = nf;
        }
    }
};

int main(){
	int n;
	while(cin>>n,n){
		DIE die;
		int ans = 1;
		FOR(i,n){
			string s; cin>>s;
			switch(s[0]){
			case 'N':
				die.rot(D);
				break;
			case 'E':
				die.rot(R);
				break;
			case 'W':
				die.rot(L);
				break;
			case 'S':
				die.rot(U);
				break;
			case 'R':
				die.f = die.getR();
				break;
			case 'L':
				die.f = die.getL();
				break;
			}
			ans += die.t;
		}
		cout << ans << endl;
	}
    return 0;
}