#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};


int main(){
    int n,q;cin >> n >> q;
    vector<int> a(n,0);
    a[0] = 1;
    int t = 0;
    for (int i = 0; i < q; i++) {
        int x,y;cin >> x >> y;
        x--,y--;
        if(x==t||y==t){
            if(x-1>=0) a[x-1]=true;
            if(x+1<n) a[x+1]=true;
            if(y-1>=0) a[y-1]=true;
            if(y+1<n) a[y+1]=true;
            t = t^x^y;
        }
        if(t-1>=0) a[t-1]=true;
        if(t+1<n) a[t+1]=true;
        swap(a[x],a[y]);
        if(t-1>=0) a[t-1]=true;
        if(t+1<n) a[t+1]=true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
