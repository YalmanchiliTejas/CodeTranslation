#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define fi first
#define se second
#define pb push_back
#define MEM(a,b) memset((a),(b),sizeof(a))
#define mod(x) ((x)%MOD)
#define pii pair<int,int>
#define wz cout<<"-----"<<endl;
const int INF_INT = 2147483647;
const ll INF_LL = 9223372036854775807LL;
const ull INF_ULL = 18446744073709551615Ull;
const ll P = 92540646808111039LL;

const ll maxn = 1e5 + 10, MOD = 1e9 + 7;
const int Move[4][2] = {-1,0,1,0,0,1,0,-1};
const int Move_[8][2] = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


void init() {

}

char mp[111][111];
bool h[111],l[111];

vector<string> r;

int main(){
//    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
//    freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
//    ios_base::sync_with_stdio(0);
    init();
    int n,m; cin >>n >>m;
    for (int i = 0; i < n; i++) cin >> mp[i];
    for (int i = 0; i <n; i++){
        bool flg = false;
        for (int j = 0; j < m; j++){
            if (mp[i][j] == '#') {
                flg = true;
            }
        }
        if (!flg) {
            h[i] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        bool flg = false;
        for (int j = 0; j < n; j++){
            if (mp[j][i] == '#') {
                flg = true;
            }
        }
        if (!flg) {
            l[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        string st;
        for (int j = 0; j < m; j++) {
            if (h[i] || l[j]) {

            } else {
                st += mp[i][j];
            }
        }
        if (st.size()) {
            r.pb(st);
        }

    }
    for (auto it:r) cout <<it <<endl;

    return 0;
}
