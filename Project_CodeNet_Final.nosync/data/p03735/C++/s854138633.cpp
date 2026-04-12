#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002



int main(){
	
	int N;
	cin>>N;
	
	vector<long long> m(2,Inf),M(2,-Inf); 
	
	vector<long long> x(N),y(N);
	for(int i=0;i<N;i++){
		cin>>x[i]>>y[i];
		if(x[i]>y[i])swap(x[i],y[i]);
		m[0] = min(m[0],y[i]);
		M[0] = max(M[0],x[i]);
	}
	m[1]=m[0];
	M[1]=M[0];
	
	vector<pair<long long,long long>> LR;
	long long xmin=Inf,ymax=-Inf;

	for(int i=0;i<N;i++){
		bool f0 = (x[i]>=m[0]);
		bool f1 = (y[i]<=M[0]);
		if(f0&&f1)continue;
		if(!f0&&!f1){
			LR.emplace_back(x[i],y[i]);
		}
		else if(!f0){
			xmin = min(xmin,x[i]);
		}
		else{
			ymax = max(ymax,y[i]);
		}
	}
	
	for(int i=0;i<LR.size();i++){
		m[0] = min(m[0],LR[i].first);
		M[1] = max(M[1],LR[i].second);
	}
	//cout<<xmin<<','<<ymax<<endl;
	long long ans = Inf;
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			auto cm = m;
			auto cM = M;
			cm[i] = min(cm[i],xmin);
			cM[j] = max(cM[j],ymax);
			ans = min(ans,(cM[0]-cm[0])*(cM[1]-cm[1]));
		}
	}
	
	cout<<ans<<endl;
		

	return 0;
}