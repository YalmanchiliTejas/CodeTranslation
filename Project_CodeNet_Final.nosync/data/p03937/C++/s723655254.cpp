#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int H, W;
char F[99][99];

int main() {
    scanf("%d%d", &H, &W);
    REP (i, H) scanf("%s", F[i]);

    bool yes = true;
    int y = 0, x = 0;

    while (1) {
	if (F[y][x] == '.') {
	    yes = false;
	    break;
	}
	F[y][x] = '-';
	if (y == H - 1 && x == W - 1) break;

	int cnt = 0;
	if (F[y+1][x] == '#') cnt++;
	if (F[y][x+1] == '#') cnt++;
	if (cnt != 1) {
	    yes = false;
	    break;
	}

	if (F[y+1][x] == '#') {
	    y++;
	} else if (F[y][x+1] == '#') {
	    x++;
	}
    }

    {
	int cnt = 0;
	REP (i, H) REP (j, W) if (F[i][j] == '#') cnt++;
	if (cnt) yes = false;
    }

    puts(yes? "Possible": "Impossible");


    return 0;
}

