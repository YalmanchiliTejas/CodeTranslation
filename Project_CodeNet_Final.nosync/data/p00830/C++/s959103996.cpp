#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
string getst(string& s){
	string t;
	int i;
	for(i=1;i<s.size();i++){
		if(s[i]=='/') break;
		t+=s[i];
	}
	s=s.substr(i);
	return t;
}
typedef vector<string> Vst;
typedef vector<int> Vi;
vector<Vi> G;
Vst names;
Vi par;
int main(){
	while(true){
		int N,M;
		cin>>N>>M;
		if(N==0) break;
		//init
		G.clear();
		names.clear();
		par.clear();
		G.pb(Vi());
		names.pb("*");
		par.pb(-1);
		
		rep(i,N){
			string s;
			cin>>s;
			int now=0;
			while(s.size()){
				string t=getst(s);
				if(s.size()==0){
					int nxt=names.size();
					names.pb(t);
					G.pb(Vi());
					G[now].pb(nxt);
					par.pb(now);
				}else{
					int nxt=-1;
					for(int v:G[now]){
						if(names[v]==t) nxt=v;
					}
					if(nxt<0){
						nxt=names.size();
						names.pb(t);
						G.pb(Vi());
						G[now].pb(nxt);
						par.pb(now);
					}
					now=nxt;
				}
			}
		}
		int I=names.size();
//		rep(i,I) cout<<i<<"   "<<names[i]<<"   "<<par[i]<<endl;
		rep(tt,M){
			int x[2]={-1,-1};
			rep(i,2){
				string s;
				cin>>s;
				int now=0;
				bool used=0,lastdot=0;
				while(s.size()){
					string t=getst(s);
					// show(t);
					// show(now);
					// show(s.size());
					if(t==".") continue;			//!!!!!
					if(t==".."){
						if(now==0||G[now].empty()){
							now=-1;
							break;
						}
						now=par[now];
//						if(s.empty()) lastdot=1;
						continue;
					}
					if(t.empty()){			// /end
						t="index.html";
						used=1;
					}
					int nxt=-1;
					for(int v:G[now]) if(names[v]==t) nxt=v;
//					show(nxt);
					if(nxt<0){
						now=-1;
						break;
					}
					now=nxt;
				}
				x[i]=now;
				if(x[i]>=0){
					if(!G[x[i]].empty()&&!used&&!lastdot){		//is directory
						int v=x[i];
						for(int u:G[v]) if(names[u]=="index.html"&&G[u].empty()) x[i]=u;
					}
					if(!G[x[i]].empty()) x[i]=-1;
				}
			}
			if(x[0]<0||x[1]<0) puts("not found");
			else if(x[0]==x[1]) puts("yes");
			else puts("no");
		}
	}
}