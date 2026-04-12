#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define intt int64_t
#define all(vec) vec.begin(), vec.end()
#define INF 2000000000

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    x -= z;
    printf("%d\n", x/(y+z));
}