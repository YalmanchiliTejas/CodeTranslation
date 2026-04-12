#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define zero(v) memset(v,0,sizeof(v))
#define rep(i,n) for(int i=0;i<(n);i++)
#define foreach(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define all(v) (v).begin(),(v).end()
template<typename T>inline bool chkmin(T &a,const T &b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T &a,const T &b){return a<b?a=b,1:0;}
typedef long long ll;
typedef unsigned uint;
const int INF=0x3f3f3f3f;
const double EPS=1e-10;
typedef pair<int,int>P;
int inline in(){int x=0,c;for(;(uint)((c=getchar())-'0')>=10;)
{if(c=='-')return -in();if(!~c)throw ~0;}do{x=(x<<3)+(x<<1)+(c-'0');}
while((uint)((c=getchar())-'0')<10);return x;}
int n,h,w;
const int Maxn=505;
string s[Maxn],t[Maxn];
uint64_t u[Maxn],v[Maxn],ans[Maxn][Maxn]={{}};
int decide[Maxn][Maxn];
void fail(){
	cout<<"-1"<<endl;
	exit(0);
}
int main(){
	cin>>n;
	h=n;w=n;
	rep(i,n){
		int x;cin>>x;
		if(x)s[i]="or";
		else s[i]="and";
	}
	rep(i,n){
		int x;cin>>x;
		if(x)t[i]="or";
		else t[i]="and";
	}
	rep(i,n){
		cin>>u[i];
	}
	rep(i,n){
		cin>>v[i];
	}
	for(int i=63;i>=0;i--){
		memset(decide,-1,sizeof(decide));
//		cout<<"i:"<<i<<endl;
		vector<P>cand_row,cand_col;
		rep(j,h){
			if(s[j]=="and"){
				if((u[j]>>i)&1){
					rep(k,w){
						decide[j][k]=1;
					}
				}else cand_row.push_back(P(j,0));	
			}else{
				if(!((u[j]>>i)&1)){
					rep(k,w){
						decide[j][k]=0;
					}
				}else cand_row.push_back(P(j,1));
			}
		}
		rep(j,w){
			if(t[j]=="and"){
				if((v[j]>>i)&1){
					rep(k,h)if(decide[k][j]==0)fail();
					rep(k,h){
						decide[k][j]=1;
					}
					
				}else cand_col.push_back(P(j,0));
			}else{
				if(!((v[j]>>i)&1)){
					rep(k,h)if(decide[k][j]==1)fail();
					rep(k,h){
						decide[k][j]=0;
					}
				}else cand_col.push_back(P(j,1));
			}
		}
//		cout<<"cand_row:"<<endl;
//		for(auto x:cand_row)cout<<x.first<<' '<<x.second<<endl;
//		cout<<"cand_col:"<<endl;
//		for(auto x:cand_col)cout<<x.first<<' '<<x.second<<endl;
		if(SZ(cand_row)>=2&&SZ(cand_col)>=2){
			for(int j=0;j<SZ(cand_row);j++){
				for(int k=0;k<SZ(cand_col);k++){
					decide[cand_row[j].first][cand_col[k].first]=(j+k)&1;
				}
			}
		}else if(SZ(cand_row)==1&&SZ(cand_col)!=0){
			bool ok=false;
			for(int j=0;j<SZ(cand_col);j++){
				bool ex=false;
				for(int k=0;k<h;k++){
					ex|=decide[k][cand_col[j].first]==cand_col[j].second;
				}
				decide[cand_row[0].first][cand_col[j].first]=ex?cand_row[0].second:cand_col[j].second;
			}
			for(int j=0;j<w;j++){
				ok|=decide[cand_row[0].first][j]==cand_row[0].second;
			}
			if(!ok)fail();
		}else if(SZ(cand_col)==1&&SZ(cand_row)!=0){
			bool ok=false;
			for(int j=0;j<SZ(cand_row);j++){
				bool ex=false;
				for(int k=0;k<w;k++){
					ex|=decide[cand_row[j].first][k]==cand_row[j].second;
				}
				decide[cand_row[j].first][cand_col[0].first]=ex?cand_col[0].second:cand_row[j].second;
			}
			for(int j=0;j<h;j++){
				ok|=decide[j][cand_col[0].first]==cand_col[0].second;
			}
			if(!ok)fail();
		}else{
			for(int j=0;j<SZ(cand_row);j++){
				bool ok=false;
				for(int k=0;k<w;k++){
					ok|=decide[cand_row[j].first][k]==cand_row[j].second;
				}
				if(!ok)fail();
			}
			for(int j=0;j<SZ(cand_col);j++){
				bool ok=false;
				for(int k=0;k<h;k++){
					ok|=decide[k][cand_col[j].first]==cand_col[j].second;
				}
				if(!ok)fail();
			}
		}
//		cout<<"decide:"<<endl;
//		for(int j=0;j<h;j++){
//			for(int k=0;k<w;k++){
//				cout<<decide[j][k];
//			}cout<<endl;
//		}
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				ans[j][k]<<=1;
				ans[j][k]|=decide[j][k];
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout<<ans[i][j]<<' ';
		}cout<<endl;
	}
	return 0;
}