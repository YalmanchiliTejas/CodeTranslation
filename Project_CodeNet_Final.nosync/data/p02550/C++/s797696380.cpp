#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int, int> PI;
typedef pair<int, pair<int, int>> PII;
static const int INF = 1010000000000000017LL;
static const double eps = 1e-12;
static const double pi = 3.14159265358979323846;
static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};
static const int ddx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
static const int ddy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N,X,M;
bool visited[1000005];
int syuki[1000005];

int modPow(int a, int n) {
    if (n == 1) return a % M;
    if (n % 2 ==1) return (a * modPow(a, n - 1)) % M;
    int t = modPow(a, n / 2);
    return (t * t) % M;
}

int search(int i,int x){
    if(i==N+1)return -1;
    if(visited[x])return x;
    visited[x]=true;
    int m=(x*x)%M;
    return search(i+1,m);
}

signed main() {
    cin>>N>>X>>M;
    int s=search(1ll,X);
    int offset=0;
    int m=X;
    int p=-1;
    for(int i=1;i<=N;++i){
        if(m==s){
            p=i;
            break;
        }
        offset+=m;
        m=(m*m)%M;
    }
    int ans;
    if(p==-1){
        int x=X;
        ans=0;
        for(int i=1;i<=N;++i){
            ans+=x;
            x=(x*x)%M;
        }
    }
    else {
        int t=0;
        int ssyuki=0;
        m=s;
        for(int i=p;i<=N;++i){
            if(m==s&&i!=p)break;
            syuki[t]=m;
            ssyuki+=syuki[t];
            m=(m*m)%M;
            t++;
        }
        int a=(N-p)/t;
        int b=(N-p)%t;
        ans=offset+ssyuki*a;
        for(int i=0;i<=b;++i)ans+=syuki[i];
    }
    cout<<ans<<endl;
}