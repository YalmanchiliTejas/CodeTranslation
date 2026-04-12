// #includes {{{
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

int N;
int x[200010], y[200010];

int main(){
	cin>>N;
	unordered_map<int,vector<int> > v;
	set<int> vals;
	int min_val = INF, max_val = -INF;
	REP(i,N){
		cin>>x[i]>>y[i];
		v[x[i]].push_back(i);
		v[y[i]].push_back(i);
		min_val = min(min_val,x[i]);
		min_val = min(min_val,y[i]);
		max_val = max(max_val, x[i]);
		max_val = max(max_val, y[i]);
		vals.insert(x[i]);
		vals.insert(y[i]);
	}
	Int ans = -INF;
	if(true){
		Int Rmin = min_val, Bmax = max_val;
		Int Rmax = -INF, Bmin = INF;
		REP(i,N){
			Rmax = max(Rmax,(Int)min(x[i],y[i]));
			Bmin = min(Bmin,(Int)max(x[i],y[i]));
		}
		ans = max(ans,(Rmax-Rmin)*(Bmax-Bmin));
	}
	if(not (v[min_val].size()==1 and v[max_val].size()==1 and v[min_val][0] == v[max_val][0])){
		Int Bmin = min_val, Bmax = -INF;
		int prev_t = -1;
		bool valid = true;
		for(auto &t:vals){
			Bmin = t;
			if(t==min_val){
				REP(i,N){
					Bmax = max(Bmax,(Int)min(x[i],y[i]));
				}
//				cerr<<"first: "<<Bmin<<" "<<Bmax<<endl;
			}else{
				for(auto &i:v[prev_t]){
					if(!(Bmin<=x[i] and x[i]<=Bmax) and !(Bmin<=y[i] and y[i]<=Bmax)){
						if(x[i]<Bmin and y[i]<Bmin){
							valid = false;
						}else{
							Bmax = INF;
							if(Bmin<=x[i])Bmax = min((Int)x[i], Bmax);
							if(Bmin<=y[i])Bmax = min((Int)y[i], Bmax);
						}
					}
				}
				if(!valid){
					break;
				}
//				cerr<<Bmin<<" "<<Bmax<<endl;
				if(min_val<Bmin and Bmax<max_val)ans = min(ans,(max_val-min_val)*(Bmax-Bmin));
			}
			prev_t = t;
		}
	}
	cout<<ans<<endl;
	return 0;
}
