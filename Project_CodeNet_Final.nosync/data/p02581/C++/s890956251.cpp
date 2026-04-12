#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};
const int MAX = 2020;
int dp[MAX][MAX],arr[MAX*3],dp2[MAX];
void upd(int f1,int f2,int x){
	dp[f1][f2] = max(dp[f1][f2],x);
	dp[f2][f1] = max(dp[f2][f1],x);
}
int main(void){
	for(int e=0;e<MAX;e++){
		for(int p=0;p<MAX;p++) dp[e][p] = -1e9;
		dp2[e] = -1e9;
	}
	int n;
	scanf("%d",&n);
	for(int e=0;e<3*n;e++) scanf("%d",&arr[e]);
	if(n==1){
		printf("1");
		return 0;
	}
	int tt = 0,mm = 0;
	for(int e=0;e<5;e++){
		for(int p=e+1;p<5;p++){
			int ll = -1,err = 0;
			for(int q=0;q<5;q++){
				if(e==q||p==q) continue;
				if(ll==-1) ll = arr[q];
				else{
					if(ll!=arr[q]) err = 1;
				}
			}
			if(err==0){
				upd(arr[e],arr[p],1);
				dp2[arr[e]] = 1;
				dp2[arr[p]] = 1;
				mm = 1;
			}else{
				upd(arr[e],arr[p],0);
				dp2[arr[e]] = max(dp2[arr[e]],0);
				dp2[arr[p]] = max(dp2[arr[p]],0);
			}
		}
	}
	for(int e=1;e<=n-2;e++){
		int lx = 5 + (e-1) * 3, rx = 5 + e * 3;
		
		// use 3 card 
		
		int ll = -1,err = 0;
		for(int q=lx;q<rx;q++){
			if(ll==-1) ll = arr[q];
			else{
				if(ll!=arr[q]) err = 1;
			}
		}
		int res = 0;
		if(err==0){
			tt++;
			res = 1;
		}
		vector<pair<pi,int> > v;
		
		// use 1 card
		
		for(int q=lx;q<rx;q++){
			if(dp[arr[q]][arr[q]]!=-1e9){
				// find 3 card
				
				int s1 = -1,s2 = -1;
				for(int r=lx;r<rx;r++){
					if(q==r) continue;
					if(s1==-1) s1 = arr[r];
					else s2 = arr[r];
				}
				v.push_back(mk(mk(s1,s2),dp[arr[q]][arr[q]] + 1 - res));
			}
			// no gain
				
			for(int r=1;r<=n;r++){
				if(dp2[r]!=-1e9){
					v.push_back(mk(mk(r,arr[q]),dp2[r] - res));
				}
			}
		}
		
		// use 2 card
		for(int q=lx;q<rx;q++){
			for(int r=q+1;r<rx;r++){
				if(arr[r]==arr[q]){
					int s1 = -1;
					for(int p=lx;p<rx;p++){
						if(p==q||r==p) continue;
						s1 = arr[p];
					}
					for(int p=1;p<=n;p++){
						if(dp[p][arr[q]]!=-1e9){
							v.push_back(mk(mk(p,s1),dp[p][arr[q]] + 1 - res));
						}
					}
				}
				v.push_back(mk(mk(arr[q],arr[r]),mm - res));
			}
		}
		for(int e=0;e<sz(v);e++){
			int f1 = v[e].x.x;
			int f2 = v[e].x.y;
			int wei = v[e].y;
			mm = max(mm,wei);
			dp2[f1] = max(dp2[f1],wei);
			dp2[f2] = max(dp2[f2],wei);
			upd(f1,f2,wei);
		}
	}
	int lastn = arr[3*n - 1];
	if(dp[lastn][lastn]!=-1e9) dp[lastn][lastn]++;
	int ans = 0;
	for(int e=1;e<=n;e++) for(int p=1;p<=n;p++) if(dp[e][p]!=-1e9){
		ans = max(ans,dp[e][p] + tt);
	}
	printf("%d",ans);
	return 0;
}
