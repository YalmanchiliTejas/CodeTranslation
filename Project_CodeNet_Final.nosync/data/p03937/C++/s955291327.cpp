#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define MAX_W (10)
bool enable[MAX_W][MAX_W];	// 通ったか
bool check[MAX_W][MAX_W];	// 通ったか
int H, W;

bool check_range(P p) {
    if ( p.first < W && p.second < H ) {
	if ( enable[p.first][p.second] ) {
	    return true;
	}
    }

    return false;
}

int main()
{

    scanf("%d %d", &H, &W);
    for ( int i = 0; i < H; i++ ) {
	for ( int j = 0; j < W; j++ ) {
	    char c;
	    scanf(" %c", &c);
	    enable[j][i] = (c== '#') ? true : false;
	}
    }

    if ( !enable[0][0] ) {
	printf("Impossible\n");
	return 0;
    }
    queue<P> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    bool ans = false;
    while ( !q.empty() ) {
	P cur = q.front();
	q.pop();
	P r = make_pair(cur.first + 1, cur.second);
	P b = make_pair(cur.first, cur.second + 1);

	if ( (cur.first == (W-1)) && (cur.second == (H-1)) ) {
	    ans = true;
	    check[W-1][H-1] = true;
	    break;
	}

	// 2通りあり
	if ( check_range(r) && check_range(b) ) {
	    break;
	}
	else if ( check_range(r) ) {
	    q.push(r);
	    check[r.first][r.second] = true;
	}
	else if ( check_range(b) ) {
	    q.push(b);
	    check[b.first][b.second] = true;
	}
    }

    for ( int i = 0; i < H; i++ ) {
	for ( int j = 0; j < W; j++ ) {
	    if ( enable[j][i] ) {
		if (!check[j][i]) {
		    ans = false;
		    break;
		}
	    }
	}
    }

    if ( ans ) {
	printf("Possible\n");
    }
    else {
	printf("Impossible\n");
    }

    return 0;
}
