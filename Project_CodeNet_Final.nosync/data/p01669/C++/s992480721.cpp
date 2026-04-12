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
typedef vector<int> vi;
typedef array<vi,3> typeA;
struct State{
	vi xs;
	typeA as;
	int turn;
	bool operator <(const State& st) const {
		if(xs!=st.xs) return xs<st.xs;
		if(as!=st.as) return as<st.as;
		return turn<st.turn;
	}
};
void showstate(State st){
	cout<<"xs:   ";
	for(int x:st.xs) cout<<x<<" ";
	puts("");
}
map<State,vi> mp,asmp;
map<State,State> nxtstate;		//0,2?????¨???
map<State,vi> tscore;			//state->nxtstate???????????°??????
vi asp(State st){
//	showstate(st);
	if(asmp.count(st)) return asmp[st];
	if(st.xs.empty()) return asmp[st]=vi(3,0);
	vi xs=st.xs;
	typeA as=st.as;
	int t=st.turn;
	vi best;
	State nxt_;
	vi tsc_(3,0);
	rep(i,3){
		if(i==t) best.pb(-100);
		else best.pb(100);
	}
	//dont action
	{
		int p=xs[0];
		vi nxs=xs;
		nxs.erase(nxs.begin());
		typeA nas=as;
		int nt=(t+1)%3;
		State nst={nxs,nas,nt};
		vi ps=asp(nst);
		ps[t]+=p;
		if(best[t]<ps[t]){
			best=ps;
			nxt_=nst;
			tsc_[t]=p;
		}
	}
	//action
	rep(i,as[t].size()){
		int y=as[t][i];
		if(xs.size()<=y) continue;
		int p=xs[y];
		vi nxs=xs;
		nxs.erase(nxs.begin()+y);
		typeA nas=as;
		nas[t].erase(nas[t].begin()+i);
		int nt=(t+1)%3;
		State nst={nxs,nas,nt};
		vi ps=asp(nst);
		ps[t]+=p;
		if(best[t]<ps[t]){
			best=ps;
			nxt_=nst;
			tsc_[t]=p;
		}
	}
	nxtstate[st]=nxt_;
	tscore[st]=tsc_;
	return asmp[st]=best;
}
pair<State,vi> nextkappa(State st){
	vi ret(3,0);
	asp(st);
	rep(i,3) ret[i]+=tscore[st][i];
	st=nxtstate[st];
	rep(i,3) ret[i]+=tscore[st][i];
	st=nxtstate[st];
	return pair<State,vi>(st,ret);
}
vi getp(State st){
	if(mp.count(st)) return mp[st];
	vi xs=st.xs;
	typeA as=st.as;
	int t=st.turn;
	if(xs.size()==2){
		vi nscore;
		nscore.pb(0);
		nscore.pb(xs[0]);
		nscore.pb(xs[1]);
		return mp[st]=nscore;
	}
	vi best;
	rep(i,3){
		if(i==t) best.pb(-100);
		else best.pb(100);
	}
	//dont action
	{
		int p=xs[0];
		vi nxs=xs;
		nxs.erase(nxs.begin());
		typeA nas=as;
		int nt=(t+1)%3;
		State nst{nxs,nas,nt};
		//minimize 0
		pair<State,vi> Pst=nextkappa(nst);
		State nxtK=Pst.fs;
		vi tmpscore=Pst.sc;
		vi ps=getp(nxtK);
		ps[t]+=p;
		rep(j,3) ps[j]+=tmpscore[j];
		if(best[0]>ps[0]) best=ps;
	}
	//action
	rep(i,as[t].size()){
		int y=as[t][i];
		if(xs.size()<=y) continue;
		int p=xs[y];
		vi nxs=xs;
		nxs.erase(nxs.begin()+y);
		typeA nas=as;
		nas[t].erase(nas[t].begin()+i);
		int nt=(t+1)%3;
		State nst={nxs,nas,nt};
		//minimize 0
		pair<State,vi> Pst=nextkappa(nst);
		State nxtK=Pst.fs;
		vi tmpscore=Pst.sc;
		vi ps=getp(nxtK);
		ps[t]+=p;
		rep(j,3) ps[j]+=tmpscore[j];
		if(best[0]>ps[0]) best=ps;
	}
	return mp[st]=best;
}

int main(){
	vector<int> xs;
	rep(i,12){
		int x;
		cin>>x;
		xs.pb(x);
	}
	reverse(all(xs));
	typeA as;
	rep(i,3){
		int aa,aaa;
		cin>>aa>>aaa;
		as[i].pb(aa-1);
		as[i].pb(aaa-1);
		sort(all(as[i]));
	}
	State be={xs,as,0};
	asp(be);
	vi fscore=tscore[be];
	be=nxtstate[be];
//	showstate(be);
	vi ans=getp(be);
	ans[0]+=fscore[0];
	cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
}