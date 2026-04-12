#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int ask(int x,int y) {
	string S(200,'0');
	S[x]=S[y]='1';
	cout<<"? "<<S<<endl;
	int ret;
	cin>>ret;
	return ret;
}

vector<pair<int,int>> V;
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,200) FOR(x,y) if(ask(x,y)==1) V.push_back({x,y});
	
	cout<<"!";
	FORR(r,V) cout<<" ("<<r.first<<","<<r.second<<")";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
