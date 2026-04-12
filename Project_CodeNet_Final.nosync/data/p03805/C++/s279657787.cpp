#include <bits/stdc++.h>
using namespace std;

/*てんぷれぞーん！*/
//static const int INF = 2147483647;
static const int INF = 1000000000;
static const long long llINF = 9223372000000000000;
static const int NIL = -1;
static const int MOD = 1000000007;
typedef long long ll;
typedef pair<int,int> P;
struct edge {int to,cost;};
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define np next_permutation
#define pq priority_queue
/* t y p o っ て 知 っ て る ゥ ！ ？ */
#define itn int
#define scnaf scanf
#define reutnr return
/*必要に応じて使ってね*/
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
//#define int ll
//#define INF llINF

void debug(){
    //puts("unko\n");
}

signed main(){
	int n,m;
    scanf("%d%d",&n,&m);
	if (n == 2) {
		puts(m ? "1" : "0");
		return 0;
	}
    bool Tokyo[n][n];
    vector<int> K;
    for(int i=0;i<n;i++){   //初期化ループ
        if(i!=0) K.pb(i);
        for(int j=0;j<n;j++){
            Tokyo[i][j] = false;
        }
    }

    debug();

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        Tokyo[a][b] = Tokyo[b][a] = true;
    }

    debug();

    int ans = 0;

    if(Tokyo[0][K[0]]){
        for(int i=0;i<n-2;i++){
            if(!Tokyo[K[i]][K[i+1]]) break;
            else if(i == n-3) ans++;
        }
    }

    while(np(all(K))){
        if(Tokyo[0][K[0]]){
            for(int i=0;i<n-2;i++){
                if(!Tokyo[K[i]][K[i+1]]) break;
                else if(i == n-3) ans++;
            }
        }
    }
    debug();

    printf("%d\n",ans);
}