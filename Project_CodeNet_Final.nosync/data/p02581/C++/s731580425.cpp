/*
{By GWj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min((a),(b))
#define check_max(a,b) a=max((a),(b))
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=2002;
int dp[MAXN][MAXN],save[MAXN],save2[MAXN][MAXN],delta/*全局增量*/,best,best2[MAXN];//滚动掉第一维 
int best_,best2_[MAXN];
int n,a[MAXN*3];
vector<vector<int> > cards;
int main(){
//	freopen("ran.in","r",stdin);
// 	freopen("Code.out","w",stdout);
	fastio;
	R(n);
	n=n+n+n;
	rb(i,1,n)
		R(a[i]);
	if(n==3){
		int rest=1;
		rb(i,1,n){
			if(a[i]==a[1]);
			else rest=0;
		}
		cout<<rest<<endl;
		return 0;
	}	
	rb(j,1,n/3){
		vector<int> tmp;
		if(j==1){
			rb(i,1,5){
				tmp.PB(a[i]);
			}
			cards.PB(tmp); 
		}	
		else{
			if(j==n/3){
				tmp.PB(a[n]);
				cards.PB(tmp);
			}
			else{
				rb(i,(j-2)*3+5+1,(j-1)*3+5){
					tmp.PB(a[i]);
				}
				cards.PB(tmp);
			}
		}
	}
	memset(dp,-63,sizeof(dp));
	rep(i,5)
		rep(j,5)
		{
			if(i!=j){
				bool ok=1;
				int las=-1;
				rep(k,5){
					if(k==i||k==j) continue;
					if(las!=-1&&las!=cards[0][k]){
						ok=0;
					}
					las=cards[0][k];
				}
				dp[cards[0][i]][cards[0][j]]=dp[cards[0][j]][cards[0][i]]=ok;
			}
		}
	best=-INF;
	memset(best2,-63,sizeof(best2));
	n/=3;
	rb(i,1,n)
	{
		rb(j,1,n){
			check_max(best2[i],dp[i][j]);
		}
		check_max(best,best2[i]);
	}
//	rb(i,1,n){
//		rb(j,1,n){
//			cout<<dp[i][j];
//			if(j!=n) cout<<" "; 
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	rb(i,1,n-2){
		rb(j,1,n)
			save[j]=dp[j][j];
		rep(j,3)
			rb(k,1,n)
				save2[cards[i][j]][k]=dp[cards[i][j]][k];
		best_=best;
		rb(j,1,n)
			best2_[j]=best2[j];
		bool ok=1;
		rep(j,3)
		{
			if(cards[i][j]==cards[i][0]);
			else{
				ok=0;
			}
		}
		if(ok){
			delta++;
			continue;
		}
		/*枚举只有拿了1张牌的情况*/
		rep(j_,3){//拿走哪一张
			//枚举另一张
			int j=cards[i][j_];
			int need=-1;
			rep(k_,3){
				int k=cards[i][k_];
				if(k_!=j_){
					if(need==-1){
						need=k;
					}
					else{
						if(need!=k) need=-1;
					}
				}
			}
			rb(k,1,n){
				check_max(dp[j][k],best2[k]);
				check_max(dp[k][j],best2[k]);
//				if(k==4){
//					cout<<j<<"-"<<dp[j][k]<<" "<<best2[k]<<endl;
//				}
				if(need>0)
				check_max(dp[k][j],save2[need][k]+1);
				check_max(dp[j][k],dp[k][j]);
				check_max(best2_[k],dp[j][k]);
				check_max(best2_[j],dp[j][k]);
				check_max(best_,dp[j][k]);
			} 
		}
//		cout<<"ONE\n";
//			rb(i,1,n){
//		rb(j,1,n){
//			cout<<dp[i][j];
//			if(j!=n) cout<<" "; 
//		}
//		cout<<endl;
//	}
//	cout<<endl;
		/*枚举拿走两张的情况*/
		rep(j_,3)
			rep(k_,3){
				if(j_==k_) continue;
				int need=0;
				rep(l_,3)
					if(l_!=j_&&l_!=k_){
						need=cards[i][l_];
					}
				int j=cards[i][j_],k=cards[i][k_];
				check_max(dp[j][k],best);
				check_max(dp[j][k],save[need]+1);
				check_max(dp[k][j],dp[j][k]);
				check_max(best2_[k],dp[j][k]);
				check_max(best2_[j],dp[j][k]);
				check_max(best_,dp[j][k]);
			}
		best=best_;
		rb(j,1,n)
			best2[j]=best2_[j],assert(best>=best2[j]);
//		cout<<i<<" "<<dp[4][4]<<endl;
//	rb(i,1,n){
//		rb(j,1,n){
//			cout<<dp[i][j];
//			if(j!=n) cout<<" "; 
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	}	
	rb(i,1,n)
		rb(j,1,n)
		{
			assert(dp[i][j]==dp[j][i]); 
		}
//	cout<<dp[cards[n-1][0]][cards[n-1][0]]<<" "<<delta<<endl; 
//	cout<<best<<" "<<dp[cards[n-1][0]][cards[n-1][0]]+1<<endl;
	check_max(best,dp[cards[n-1][0]][cards[n-1][0]]+1);
	cout<<best+delta<<endl;
	return 0;
}/*
5
1 2 5 3 3 5 3 1 3 4 3 2 5 1 4 
*/