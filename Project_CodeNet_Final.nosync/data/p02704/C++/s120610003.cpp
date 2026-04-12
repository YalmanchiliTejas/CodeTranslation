/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL unsigned long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
void er(){
	cout<<-1<<endl;
	exit(0);
}
	int n;
	LL res[501][501],s[501],t[501],u[501],v[501];
	int zero[1001];
	bool mat[501][501],con[501][501],con1[1001];
int main(){
	fastio;
	cin>>n;
	rb(i,1,n) cin>>s[i];
	rb(i,1,n)cin>>t[i];
	rb(i,1,n) cin>>u[i];
	rb(i,1,n) cin>>v[i];
	LL base=1;
	rep(ID,64){
		memset(zero,0,sizeof(zero));
		memset(con1,0,sizeof(con1));
		memset(con,0,sizeof(con));
		memset(mat,0,sizeof(mat));
		rb(i,1,n)
			if((!s[i])&&(u[i]&1)){
				con1[i]=1;
				rb(j,1,n){
					con[i][j]=1;
					mat[i][j]=1;
				}
			}
			else
			if((s[i])&&(!(u[i]&1))){con1[i]=1;
				rb(j,1,n)
					{
						con[i][j]=1;
						mat[i][j]=0;
					}
			}
		rb(j,1,n)
		{
			if((!t[j])&&(v[j]&1)){con1[j+n]=1;
				rb(i,1,n){
					if(con[i][j]&&(!mat[i][j])){
						er();	
					}
					con[i][j]=1;
					mat[i][j]=1;
				}
			}
			else
			if(t[j]&&(!(v[j]&1))){con1[j+n]=1;
				rb(i,1,n){
					if(con[i][j]&&mat[i][j]){
						er();
					}
					con[i][j]=1;
					mat[i][j]=0;
				}
			}
		}
		rb(i,1,n){
			rb(j,1,n){
				if(!(mat[i][j]&1)){
					zero[i]++;
				}
				if(!(mat[j][i]&1)){
					zero[i+n]++;
				}
			}
			if(zero[i]==0&&(s[i]==0&&((u[i]&1)==0))){
				er();
			}
			if(zero[i+n]==0&&t[i]==0&&(v[i]&1)==0){
				er();
			}
		}
		rb(i,1,n){
			if(s[i]&&(u[i]&1)){
				rb(j,1,n){
					if(mat[i][j]) break;
					if(!con[i][j]){
						if(t[j]){
							mat[i][j]=1;
							break;				
						}
						else{
							if(zero[j+n]>1){
								zero[j+n]--;
								mat[i][j]=1;
								break;
							}
						}
					}
				}
				bool ok=0;
				rb(j,1,n){
					ok|=mat[i][j];
				}
				if(!ok){
					er();
				}
			}
		}
		rb(j,1,n){
			if(t[j]&&(v[j]&1)){
				rb(i,1,n){
					if(mat[i][j]) break;
					if(!con[i][j]){
						if(s[i]){
							mat[i][j]=1;
							break;
						}
						else{
							if(zero[i]>1){
								zero[i]--;
								mat[i][j]=1;
								break;
							}
						}
					}
				}
				
				bool ok=0;
				rb(i,1,n){
					ok|=mat[i][j];
				}
				if(!ok){
					er();
				}
			}
		}
		rb(i,1,n)
			u[i]>>=1,v[i]>>=1;
		rb(i,1,n)
			rb(j,1,n)
				res[i][j]+=base*mat[i][j];
		base<<=1;
	}
	rb(i,1,n){
		rb(j,1,n) cout<<res[i][j]<<" ";cout<<endl;
	} 
	return 0;
}
/*
3
1 999 3
45 29 18446744073709551615
0 1 99
1 1 1
1 1 1
999 18446744073709551615 99
45 1023 18446744073709551615
*/