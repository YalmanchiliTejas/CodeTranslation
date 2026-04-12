#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(), (x).end()
#define SYAMU(a) memset(a,0,sizeof(a))
#define pb push_back
#define mp make_pair

vector<pair<int,int> > a; // score, num;
int used[810];

int main() {
    int x,y;
    while(scanf("%d,%d",&x,&y)) {
        if(x==0) break;
        a.pb(mp(y,x));
    }

    sort(a.rbegin(),a.rend());

    int q, n = a.size();
    while(cin>>q) {
        int rank = 0;
        SYAMU(used);
        rep(i,n) {
            if(!used[a[i].first]) {
                used[a[i].first]++; rank++;
            }
            if(a[i].second == q) {
                cout << rank << endl;
            }
        }
    }


    return 0;
}