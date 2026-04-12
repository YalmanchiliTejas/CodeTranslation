#include <iostream>
#include <iomanip>
#include <math.h>
#include <map>
#include <list>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <string.h>
// #include <limits.h>

#define FOR(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define FORUL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define FORULE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#if defined(_MSC_VER) || __cplusplus > 199711L
#define AUTOVAR(newvar,v) auto newvar = (v)
#else
#define AUTOVAR(newvar,v) __typeof(newvar) r = (v)
#endif
#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define MEMSET(m,v) memset(m,v,sizeof(m))

typedef long long				 ll;
typedef unsigned long long		ull;

#define INTMAX  99999999

#define DEBUG 0

#if DEBUG
#define DOUT cout<<"["<<__LINE__<<"]:"
#else
#define DOUT 0 && cout
#endif

using namespace std;

int H,W;
#define MAX_HW 8
string A[MAX_HW];

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);

	cin >> H >> W;

	FOR(h,H) {
		cin >> A[h];
	}

	int h=0;
	int w=0;
	bool result = true;
	while(true) {
		DOUT << "A["<<h<<"]["<<w<<"]=="<<A[h][w]<<endl;
		int nh = -1;
		int nw = -1;
		A[h][w] = '*';
		if(h>0) {
			if(A[h-1][w]=='#') {
				DOUT << "FALSE: A[h-1][w]=="<<A[h-1][w]<<endl;
				result = false;
				break;
			}
		}
		if(w>0) {
			if(A[h][w-1]=='#') {
				result = false;
				DOUT << "FALSE: A[h-1][w]=="<<A[h][w-1]<<endl;
				break;
			}
		}
		if(h<H-1) {
			if(A[h+1][w]=='#') {
				DOUT << "TRUE: A[h+1][w]=="<<A[h+1][w]<<endl;
				nh = h+1;
				nw = w;
			}
		}
		if(w<W-1) {
			if(A[h][w+1]=='#') {
				DOUT << "TRUE: A[h][w+1]=="<<A[h][w+1]<<endl;
				if(nh>=0 || nw>=0) {
					DOUT << "false: DOUBLE#"<<endl;
					result = false;
					break;
				}
				nh = h;
				nw = w+1;
			}
		}
		if(nh>=0&&nw>=0) {
			h=nh;
			w=nw;
			continue;
		}
		if(h==H-1&&w==W-1) {
			break;
		}
		result = false;
		break;
	}

	if(result) {
		cout << "Possible"<<endl;
	}
	else {
		cout << "Impossible"<<endl;
	}

	return 0;
}

