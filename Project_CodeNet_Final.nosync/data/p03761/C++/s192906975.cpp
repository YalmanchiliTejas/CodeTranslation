#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <limits.h>
#include <memory.h>


using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,n) for(int i=0;i<(int)n;++i)
#define FORNUM(p, x) for (int num = p; num < (int)(x); ++num)
#define FORI(p, x) for (int i = p; i < (int)(x); ++i)
#define FORJ(p, x) for (int j = p; j < (int)(x); ++j)
#define FORK(p, x) for (int k = p; k < (int)(x); ++k)
#define FORL(p, x) for (int l = p; l < (int)(x); ++l)

typedef vector<double> vec;
typedef vector<vec> mat;

int n;
string s[55];
int dat[55][30];
int ans[30];

int main() {

	cin>>n;
	FORI(0,n){
		cin>>s[i];
	}
	FORI(0,n){
		FORJ(0,s[i].size()){
			dat[i][s[i][j]-'a']++;
		}
	}

	FORJ(0,26){
		ans[j]=dat[0][j];
	}
	FORI(1,n){
		FORJ(0,26){
			ans[j]=min(ans[j], dat[i][j]);
		}
		
	}

	FORI(0,26){
		FORJ(0,ans[i]){
			printf("%c", i+'a');
		}
	}
	printf("\n");
	return 0;
}


