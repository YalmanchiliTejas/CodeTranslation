#include <bits/stdc++.h>
using namespace std;

#define len(x)  (int((x).size()))
#define append push_back
#define pp make_pair
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define kk(n)    ff(k, n)
#define xx(n)    ff(x, n)
#define yy(n)    ff(y, n)
#define ii(n)    ff(i, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define kkk(a, b) fff(k, a, b)
#define xxx(a, b) fff(x, a, b)
#define yyy(a, b) fff(y, a, b)
#define iii(a, b) fff(i, a, b)
#define bb begin()
#define ee end()
#define uu first
#define vv second
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#define zz(array, byte)   memset(array, byte, sizeof(array));

using LL = long long;
using DD = long double;
using pii = pair<int, int>;


const LL  INFLL  = 0x7f7f7f7f7f7f7f7fLL;
const int INFint = 0x7f7f7f7f;  //Works with memset(..).
   

vector<vector<int> > al;

bool found = false;

bool dfs_isOdd(int from, int parent) {
    int c = 0;
    ii (len(al[from])) {
        int nei = al[from][i];
        if (parent == nei)
            continue;
        bool below = dfs_isOdd(nei, from);
        if (below)
            ++c;
    }

    if (c >= 2)
        found = true;

    return (c == 0);
    
}


int main() {
    ios_base::sync_with_stdio(false);     cin.tie(NULL);
    //cout << '\n';     //Avoid flushing with endl.
    cout.precision(16);


    int N;
    cin >> N;

    al.resize(N);
    int start = 0;
    ii (N-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        al[a].append(b);
        al[b].append(a);
        if (len(al[a]) >= 2)
            start = a;
        if (len(al[b]) >= 2)
            start = b;
    }

    dfs_isOdd(start, -1);
    if (found) {
        cout << "First\n";
    } else
        cout << "Second\n";
    

    return 0;
}

