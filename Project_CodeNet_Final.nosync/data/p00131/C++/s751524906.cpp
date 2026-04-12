#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(), (v).end()
#define rev(s) (s).rbegin(), (s).rend()
#define MP make_pair
#define X first
#define Y second
#define debug(x) cout << #x << " = " << x << endl;
#define sq(x) ((x)*(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;

const int MAX_N = 11;
int v[MAX_N][MAX_N];

int answer[MAX_N][MAX_N];
int dx[] = {1, 0, -1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

int isOn(int x, int y){
    int sum = v[y][x];
    rep(i,5){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
        sum += answer[ny][nx];
    }
    return sum%2;
}

bool check(int state){
	memset(answer, 0, sizeof(answer));
    rep(i, 10){
        answer[0][9-i] = (state>>i)&1;
    }
    FOR(i, 1, 10){
        rep(j, 10){
           if(isOn(j, i-1)) answer[i][j] = 1;
        }
    }

    rep(i, 10){
        if(isOn(i, 9)) return false;
    }

    return true;
}

int main(){
	int dataset;
	cin >> dataset;
	while(dataset--){
		rep(i, 10) rep(j, 10) cin >> v[i][j];
        for(int state = 0; state < (1<<10); state++){
            if(check(state)) break;
        }

        rep(i, 10){
            rep(j, 10) cout << (j?" ":"") << answer[i][j];
            cout << endl;
        }
	}

    return 0;
}