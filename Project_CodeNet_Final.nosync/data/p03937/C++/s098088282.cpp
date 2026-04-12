#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char A[10][10];
queue<pair<pair<int, int>, int> > Q;

int main(void) {
    int h, w, visited = 0;
    cin >> h >> w;
    for(int i=0; i<h; i++) cin >> A[i];
    for(int i=0; i<h; i++) for(int j=0; j<w; j++) {
        if(A[i][j] == '#') visited++;
    }
    Q.push(make_pair(make_pair(0, 0), 1));
    while(!Q.empty()) {
        int y = Q.front().first.first, x = Q.front().first.second;
        int v = Q.front().second;
        Q.pop();
        if(y == h-1 &&  x == w-1 && v == visited) return !printf("Possible\n");

        if(A[y][x] == '.') continue;
        if(y < h-1) Q.push(make_pair(make_pair(y+1, x), v+1));
        if(x < w-1) Q.push(make_pair(make_pair(y, x+1), v+1));
    }

    return !printf("Impossible\n");
}