#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)
#define MAX_N 210
#define MAX_V 10
#define MAX_M 101
#define yn(f) (f?"Yes":"No")
#define YN(f) (f?"YES":"NO")
#define pro "はいプロ　世界一○○が上手　○○界のtourist　○○時代の終焉を告げる者　実質○○　○○するために生まれてきた男"

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int W, H, N;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

bool fld[MAX_N*6][MAX_N*6];

int compress(int *x1, int *x2, int w){
	vector<int> xs;
	
	for(int i = 0; i < N; i++){
		for(int d = -1;d <= 1; d++){
			int tx1 = x1[i] + d, tx2 = x2[i] + d;
			if(0 <= tx1 && tx1 <= w) xs.push_back(tx1);
			if(0 <= tx2 && tx2 <= w) xs.push_back(tx2);
		}
	}
	
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	
	for(int i = 0; i < N; i++){
		x1[i] = find(xs.begin(),xs.end(),x1[i]) - xs.begin();
		x2[i] = find(xs.begin(),xs.end(),x2[i]) - xs.begin();
	}
	
	return xs.size();
}

void solved(){
	W = compress(X1,X2,W);
	H = compress(Y1,Y2,H);
	
	memset(fld, 0, sizeof(fld));
	for(int i = 0; i < N; i++){
		for(int y = Y1[i]; y <= Y2[i]; y++){
			for(int x = X1[i]; x <= X2[i]; x++){
				fld[y][x] = true;
			}
		}
	}
	int ans = 0;
	// for(int y = 0; y < H; y++){
		// for(int x = 0; x < W; x++){
			// cout<<fld[y][x]<<" ";
		// }cout<<endl;
	// }
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){
			if(fld[y][x]) continue;
			bool flag = false;
			ans++;
			queue<pair<int, int>> que;
			que.push(make_pair(x,y));
			while(!que.empty()){
				int sx = que.front().first, sy = que.front().second;
				que.pop();
				
				for(int i = 0; i < 4; i++){
					int tx = sx + dx[i], ty = sy + dy[i];
					if(tx < 0 || W <= tx || ty < 0 || H <= ty){
						flag = true;
						continue;
					}
					if(fld[ty][tx]) continue;
					que.push(make_pair(tx,ty));
					fld[ty][tx] = true;
				}
			}
			if(flag)ans--;
		}
	}
	cout<<ans+1<<endl;
}

signed main(){
	while(true){
		int l, t, r, b, i;
		H = W = (int)(1e6)*2;
		cin>>N;
		if(!N) break;
		for(int j = 0; j < N; j++){
			cin>>l>>t>>r>>b;
			l*=2,t*=2,r*=2,b*=2;
			 // l++,t++,r++,b++;
			//l,t,r,b;
			i = j*4;
			X1[i]   = l;X2[i]   = r;Y1[i]   = t;Y2[i]   = t;
			X1[i+1] = l;X2[i+1] = r;Y1[i+1] = b;Y2[i+1] = b;
			X1[i+2] = l;X2[i+2] = l;Y1[i+2] = b;Y2[i+2] = t;
			X1[i+3] = r;X2[i+3] = r;Y1[i+3] = b;Y2[i+3] = t;
		}
		N *= 4;
		solved();
	}
	
	return 0;
}
