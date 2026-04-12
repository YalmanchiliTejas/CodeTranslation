/* << IN THE NAME OF GOD >> */
#include <bits/stdc++.h>
using namespace std;



#define err(x) cerr << #x  << " = "<<  x << '\n'
#define out(x) cout << x << '\n'
#define forp(i, r, l) for(int i = int(r); i < int(l); i++)
#define forn(i, r, l) for(int i = int(r); i > int(l); i--)
#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll ,ll> pll;
const int maxn = 1e2 + 120;

bool t[maxn][maxn] ,a[maxn] ,b[maxn];
int h ,w;

int main(){FAST;   
    cin >> h >> w;
    forp(i ,0 ,h){
        bool s = 1;

        forp(j ,0 ,w){
            char ch;
            
            cin >> ch;
            ch == '#'? t[i][j] : t[i][j] = 1;
            if(!t[i][j])
                s = 0;
            }
        if(s)
            a[i] = 1;
    }
    forp(i ,0 ,w){
        bool s = 1;
        forp(j ,0 ,h)
            if(!t[j][i])
                s = 0;
        if(s)
            b[i] = 1;
    }
    forp(i ,0 ,h){
        forp(j ,0 ,w)
            if(!a[i] && !b[j])
                t[i][j] ? cout << '.' : cout << '#';
        cout << '\n';
    }



return 0;
}
 








