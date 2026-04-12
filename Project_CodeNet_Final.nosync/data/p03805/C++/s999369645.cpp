#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
 
 
signed main(){
 
	lli n,m;
	cin>>n>>m;
	vector<vector<lli>> v(n);
	REP(i,0,m){
		lli a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
 
	vector<lli> per;
	REP(i,0,n)per.push_back(i);
 
	lli ans=0;
	do{
		if(DEBUG)REP(i,0,per.size())cout<<per[i]<<" ";
 
		bool ok=true;
		lli s = per[0];
		if(s!=0)continue;
		REP(i,1,n){
			lli next = per[i];
 
			if(DEBUG)cout<<"s="<<s<<"next="<<next<<endl;
			bool fOk = false;
			REP(k,0,v[s].size()){
				if(DEBUG)cout<<"v="<<v[s][k]<<endl;
				if(v[s][k]==next){
					fOk = true;
					break;
				}
			}
			if(!fOk){
				ok=false;
				break;
			}
			s = next;
		}
		if(ok){
			ans++;
		}
 
	}while(next_permutation(per.begin(),per.end()));
 
	cout<<ans<<endl;
 
  return 0;
}