#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
typedef pair<LL,LL> P;
vector<P>v;
LL x[200001];
LL y[200001];

int main(){
	cin>>N;
	LL ma=0;
	LL mi=10e10;
	REP(i,N){
	    cin>>x[i]>>y[i];
	    if(x[i]>y[i]){
	       LL temp=x[i];
	       x[i]=y[i];
	       y[i]=temp;
	    }
	    mi=min(mi,x[i]);
	    ma=max(ma,y[i]);
	    v.push_back(P(x[i],y[i]));
	}
	sort(v.begin(),v.end());
	if(N==1){
	   cout<<0<<endl;
	   return 0;
	}
	//R=min,B=max
	LL ans;
	{
	   LL a=mi;
	   LL b=0;
	   LL c=10e10;
	   LL d=ma;
           REP(i,N){
               b=max(x[i],b);
               c=min(y[i],c);
           }
           ans=(b-a)*(d-c);
	}
	//R=min R=max
	{ LL red=ma-mi;
	  LL mma=v[v.size()-1].first;
	  LL mmi=v[0].first;
	  LL mmmi=10e10;
	  ans=min(ans,red*(mma-mmi));
	  REP(i,v.size()){
	      if(i==0)continue;
	      mmmi=min(v[i-1].second,mmmi);
	      mmi=min(mmmi,v[i].first);
	      mma=max(v[i-1].second,mma);
	     // cout<<mma<<" "<<mmi<<endl;
	      ans=min(ans,red*(mma-mmi));
	  }
	}
	cout<<ans<<endl;
	return(0);
}