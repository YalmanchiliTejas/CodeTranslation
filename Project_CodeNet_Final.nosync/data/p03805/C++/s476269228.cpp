#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) max_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N,M; cin >> N >> M;
    vei a(M), b(M);
    rep(i,M) cin >> a[i] >> b[i];
    bool connect[N][N];
    memset(connect, false, sizeof(connect));
    int v[N-1];
    rep(i,N) v[i] = i+2;//2~Nまでの番号の配列

    rep(i,M) {
        connect[a[i]-1][b[i]-1] = true;
        connect[b[i]-1][a[i]-1] = true;
    }

    int ans = 0;

    do{
        bool check = true;
        rep(i,N-1) {
            if(i == 0 and !connect[i][v[i]-1]) {
                check = false;
                break;
            }
            if(i != 0 and !connect[v[i-1]-1][v[i]-1]) {
                check = false;
                break;
            }
        }
        if(check) ans++;
    }while(next_permutation(v,v+N-1));
    
    cout << ans << endl;
    return 0;

}