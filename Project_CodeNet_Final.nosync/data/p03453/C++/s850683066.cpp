#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pii pair<int, int>
#define p3i pair<pii, int>
#define pll pair<ll, ll>
#define p3l pair<pll, ll>
#define lseg L, (L+R)/2, N*2+1
#define rseg (L+R)/2+1, R, N*2+2
#define ub upper_bound
#define lb lower_bound
#define pq priority_queue
#define MN 1000000007
#define fox(k, x) for (int k=0; k<x; ++k)
#define fox1(k, x) for (int k=1; k<=x; ++k)
#define foxr(k, x) for (int k=x-1; k>=0; --k)
#define fox1r(k, x) for (int k=x; k>0; --k)
#define ms multiset
#define flood(x) memset(x, 0x3f3f3f3f, sizeof x)
#define drain(x) memset(x, 0, sizeof x)
#define rng() (rand() >> 3)*rand()
#define scan(X) do{while((X=getchar())<'0'); for(X-='0'; '0'<=(_=getchar()); X=(X<<3)+(X<<1)+_-'0');}while(0)
char _;
#define pi 3.14159265358979323846

int n, m, a, b, N, P, x, y, cnt[2][100005], ans;
ll d[2][100005], D, dis;
vector<pii> v[100005];
pq<pair<pair<ll, int>, int> > q;
void add(int&A, int B){
    A=(A+B)%MN;
}
void dijk(int R, int T){
    cnt[T][0]=1;
    q.push(mp(mp(0, R), 0));
    while(!q.empty()){
        N=q.top().x.y; D=-q.top().x.x; P=q.top().y; q.pop();
        if (D>d[T][N]) continue;
        if (D<d[T][N]){
            d[T][N]=D;
            fox(l, v[N].size()){
                q.push(mp(mp(-D-v[N][l].y, v[N][l].x), N));
            }
        }
        if (D==d[T][N]){
            add(cnt[T][N], cnt[T][P]);
        }
    }
}
int main(){
    fox(l, 100002) d[0][l]=d[1][l]=(1LL<<60);
    scanf("%i%i%i%i", &n, &m, &x, &y);
    fox(l ,m){
        //a=l+1;
        //b=l+2; D=1000000000;
        scanf("%i%i%i", &a, &b, &D);
        v[a].pb(mp(b, D));
        v[b].pb(mp(a, D));
    }
    dijk(x, 0); dijk(y, 1);
    ans=(1LL*cnt[0][y]*cnt[1][x])%MN;
    dis=d[0][y];
    //cout << ans << endl;
    fox1(l, n){
        //cout << d[0][l] << ' ' << d[1][l] << endl;
        if (d[0][l]==d[1][l] && d[0][l]+d[1][l]==dis){
            add(ans, -((1LL*cnt[0][l]*cnt[1][l]%MN)*((1LL*cnt[0][l]*cnt[1][l]%MN))%MN));
        }
        fox(l2, v[l].size()){
            N=v[l][l2].x;
            if (d[0][l]+d[1][N]+v[l][l2].y!=dis) continue;
            if (d[0][l]+v[l][l2].y>d[1][N] &&
                d[1][N]+v[l][l2].y>d[0][l]){
                add(ans, -((1LL*cnt[0][l]*cnt[1][N]%MN)*(1LL*cnt[0][l]*cnt[1][N]%MN)%MN));
            }
        }
    }
    if (ans<0) ans+=MN;
    cout << ans;
    return 0;
}
