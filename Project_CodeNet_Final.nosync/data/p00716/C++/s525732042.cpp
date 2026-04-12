#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int m;
	cin>>m;
	rep(z,m){
		long long money;
		int time,n;
		cin>>money>>time>>n;
		vector<long long> ans;
		long long memory=money;
		rep(u,n){
			int tax,fee;
			long double percent;
			cin>>tax>>percent>>fee;
			long long nenri=0;
			money=memory;
			rep(i,time){
				if(tax==0){//???????????´???
					nenri+=(int)money*percent;
					money-=fee;
				}else{//???????????´???
					money=(long long)money*(1+percent)-fee;
				}
			}
			if(tax==0)money+=nenri;
			ans.push_back(money);
		}
		sort(ans.begin(),ans.end());
		cout<<ans[ans.size()-1]<<endl;
	}
	return 0;
}