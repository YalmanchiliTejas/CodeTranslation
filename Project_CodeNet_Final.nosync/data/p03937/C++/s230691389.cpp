#include <bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int INFTY=1e9;
const int N=20;

char f[N][N];

int main() {
    int i, j, h, w;
    scanf("%d%d", &h, &w);
    for(i=0; i<h; i++) scanf("%s", f[i]);
    i=j=0;
    while(i!=h-1 || j!=w-1) {
        f[i][j]='.';
        if(f[i+1][j]=='#') { i++; continue; }
        if(f[i][j+1]=='#') { j++; continue; }
        printf("Impossible\n");
        return 0;
    }
    f[i][j]='.';
    for(i=0; i<h; i++) for(j=0; j<w; j++) if(f[i][j]=='#') {
        printf("Impossible\n");
        return 0;
    }
    printf("Possible\n");
    return 0;
}