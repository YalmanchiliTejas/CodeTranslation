#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e18 + 3)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
bool Add(int &a,int b){a = (a + b) % MOD;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}
const int n_max = 101010;
int n,m;
struct edge{
    int cost, to;
};

vector<edge> E[n_max];

struct vertice{
    int dist, baai;
};

void dijkstra(int s, vertice* V){
    reversed_priority_queue< pair<int, int> > Q;
    Q.push( mp(0,s) );
    REP(i,n){
        V[i].dist = INF;
        V[i].baai = 0;
    } 
    V[s].dist = 0;
    V[s].baai = 1;
    int used[n];
    REP(i,n) used[i] = false;
    while(Q.size()){ 
        int tmpv = Q.top().se;
        Q.pop();
        if(used[tmpv]) continue;
        used[tmpv] = true;
        itrfor(itr, E[tmpv]){
            if( V[itr->to].dist > V[tmpv].dist + itr->cost ){
                V[itr->to].dist = V[tmpv].dist + itr->cost;
                V[itr->to].baai = V[tmpv].baai;
                Q.push( mp(V[itr->to].dist, itr->to) );
            }
            else if( V[itr->to].dist == V[tmpv].dist + itr->cost){
                V[itr->to].baai += V[tmpv].baai;
                V[itr->to].baai %= MOD;
            }
        }

    }
}


signed main(){
    cin >> n >> m;
    int s,t;
    cin >> s >> t ;
    s --;
    t --;
    REP(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a --;
        b --;
        E[a].push_back( edge{c,b} );
        E[b].push_back( edge{c,a});
    }

    vertice V[n];
    dijkstra(s,V);
    int saitan = V[t].dist;
    int souwa = V[t].baai;
    vertice V2[n];
    dijkstra(t,V2);

    int ans = 0;

    /*
    REP(i,n){
        cout << endl;
        debug(i + 1);
        debug(V[i].baai);
        debug(V[i].dist);
    }
    */
    REP(i,n){
        if( 2 * V[i].dist < saitan){
            itrfor(itr,E[i]){
                if(2 * V[itr->to].dist > saitan and V[i].dist + V2[itr->to].dist + itr->cost == saitan ){
                    int r1 = (V[i].baai * V2[itr->to].baai ) % MOD;
                    int r2 = souwa + MOD - r1;
                    r2 %= MOD;
                    ans += (r1 * r2) % MOD;;
                    ans %= MOD;
                }
            }
        }
        else if( 2 * V[i].dist == saitan and V[i].dist + V2[i].dist == saitan){
            int r1 = V[i].baai * V2[i].baai % MOD;
            int r2 = souwa + MOD - r1;
            r2 %= MOD;
            ans += (r1 * r2 ) % MOD;
            ans %= MOD;
        }

    }
    cout << ans << endl;




}