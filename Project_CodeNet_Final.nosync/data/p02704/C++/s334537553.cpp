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
bool mat[505][505],con[505][505],need[1020],con1[1020];
bool S[505],T[505],u[505],v[505];
LL U[505],V[505];
LL res[505][505];
int n;
const int GRAPH_SIZE=/*here->>>*/  251010 /*<<<=here*/;
int pin[GRAPH_SIZE],dep[GRAPH_SIZE],s,t;
struct EDGE{
	int u,v,c;
};
vector<EDGE> e;
vector<int >  each[GRAPH_SIZE];
bool bfs(){
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		for(auto it:each[now]){
			int next=e[it].v;
			if(e[it].c)
			if(dep[next]>dep[now]+1){
				dep[next]=dep[now]+1;
				Q.push(next);
			}
		}
	}
	return dep[t]!=INF;
}
int dfs(int now,int flow){
	if(now==t){
		return flow;
	}
	for(int & i= pin[now];i<each[now].size();i++){
		int it=each[now][i];
		if(e[it].c&&dep[e[it].v]==dep[now]+1){
			int tmp;
			if(tmp=dfs(e[it].v,min(flow,e[it].c))){
				e[it].c-=tmp;
				e[it^1].c+=tmp;
				return tmp;
			}
		}
	}
	return 0;
}
int Dinic(){
	int max_flow=0;
	rep(i,GRAPH_SIZE)
	{
		
		dep[i]=INF;
	}
	dep[s]=0;
	while(bfs()){
		memset(pin,0,sizeof(pin));
//		rep(i,GRAPH_SIZE){
//			pin[i]=0;
//		}
		int tmp;
		while(tmp=dfs(s,INF)){
			max_flow+=tmp;
		}
		memset(dep,0x3f,sizeof(dep));
	//	rep(i,GRAPH_SIZE){
//			dep[i]=INF;
//		}
		dep[s]=0;
	}
	return max_flow;
}
void make_edge(int U,int V,int C){
	EDGE tmp;
	tmp.u=U;
	tmp.v=V;
	tmp.c=C;
	e.PB(tmp);
	each[U].PB(e.size()-1);
	swap(tmp.u,tmp.v);
	tmp.c=0;
	e.PB(tmp);
	each[V].PB(e.size()-1);
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n) cin>>S[i];
	rb(i,1,n) cin>>T[i];
	rb(i,1,n) cin>>U[i];
	rb(i,1,n) cin>>V[i];
	LL base=1;
//	vector<vector<int> > Tmp_save(GRAPH_SIZE);	
	rep(ID,64)
	{
		e.clear();
//		fill(each,each+GRAPH_SIZE,vector<int> (0));
		rep(i,GRAPH_SIZE)
			each[i].clear();
//		each=Tmp_save;
		memset(con1,0,sizeof(con1));
		memset(mat,0,sizeof(mat));
		memset(con,0,sizeof(con));
		rb(i,1,n){
			u[i]=U[i]&(LL)(1);
			U[i]>>=1;
		}	
		rb(i,1,n){
			v[i]=V[i]&(LL)(1);
			V[i]>>=1;
		}
		rb(i,1,n){
			if(!S[i]){
				//AND
				if(u[i]){
					con1[i]=1;
					rb(j,1,n)
						mat[i][j]=1,con[i][j]=1;						
				}
				else{
					need[i]=0;
				}
			}
			else{
				if(!u[i]){
					con1[i]=1;
					rb(j,1,n)
						mat[i][j]=0,con[i][j]=1;
				}
				else{
					need[i]=1;
				}
			}
		}
		rb(j,1,n){
			if(!T[j]){
				if(v[j]){
					con1[j+n]=1;
					rb(i,1,n)
						{
							if(con[i][j]&&(!mat[i][j])){
								cout<<-1<<endl;
								return 0;
							}
							mat[i][j]=1,con[i][j]=1;
						}
				}
				else{
					need[j+n]=0;
				}
			}
			else{
				if(!v[j]){
					con1[j+n]=1;
					rb(i,1,n)
					{
						if(con[i][j]&&mat[i][j]){
							cout<<-1<<endl;
							return 0;
						}
						mat[i][j]=0,con[i][j]=1;
					}
				}
				else{
					need[j+n]=1;
				}
			}
		}
		
		rb(i,1,n)
		{
			if(con1[i]) continue;
			bool ok=1,flag=0;
			rb(j,1,n){
				ok&=con[i][j];
				flag|=(mat[i][j]==need[i]);
			}
			if(ok){
				if(flag){
					con1[i]=1;
				}
				else{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
		rb(j,1,n){
			if(con1[n+j]) continue;
			bool ok=1,flag=0;
			rb(i,1,n){
				ok&=con[i][j];
				flag|=(mat[i][j]==need[j+n]);
			}
			if(ok){
				if(flag){
					con1[j+n]=1;
				}
				else{
					cout<<-1<<endl;
					return 0;
				}
			}
		}
		rb(i,1,n){
			if(!con1[i]){
				rb(j,1,n){
					if(con[i][j]){
						if(mat[i][j]==need[i]){
							con1[i]=1;
							break;
						}
					}
				} 
			} 
		}
		rb(j,1,n){
			if(!con1[j+n]){
				rb(i,1,n)
				{
					if(con[i][j]){
						if(mat[i][j]==need[j+n]){
							con1[j+n]=1;
							break;
						}
					}
				}
			} 
		}
//		break;
		s=0,t=GRAPH_SIZE-1;
		int cnnt=0;
		rb(i,1,n)
			rb(j,1,n){
				if(!con[i][j]){
					if(need[i]==need[j+n]){
						con1[i]=con1[j+n]=1;
						if(need[i]){
							mat[i][j]=1;
						}
						else{
							mat[i][j]=0;
						}
					}
					else{
						make_edge(s,(i-1)*n+j,1);
						make_edge((i-1)*n+j,n*n+i,1);
						make_edge((i-1)*n+j,(n*n)+n+j,1); 
					}
				}
			}
//		break;
		rb(i,1,n){
			if(!con1[i]){
				make_edge(n*n+i,t,1);
				cnnt++;
			}	
			if(!con1[i+n]){
				make_edge((n+1)*n+i,t,1);
				cnnt++;
			}
		}
//		break;
		int max_flow=Dinic();
		if(max_flow>cnnt){
			while(1);
		}
		if(max_flow<cnnt){
//			while(1);
			cout<<-1<<endl;
			return 0;
		}
		rep(i,e.size()){
			if(i&1){
				if(e[i].u==t) continue;
				if(e[i].v==s) continue;
				if(e[i].c==1){
					int x,y,zz;
					zz=e[i].u;
					x=e[i].v/n+1;
					y=e[i].v%n;
					if(y==0){
						y=n;
						x--;
					}
					zz-=n*n;
					mat[x][y]=need[zz];
				}
			}
		}
		rb(i,1,n)
			rb(j,1,n)
				res[i][j]+=base*mat[i][j]; 
		base<<=1;
	}
	rb(i,1,n)
	{
		rb(j,1,n) cout<<res[i][j]<<" ";
		cout<<endl;
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