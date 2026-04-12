#include <iostream>
#include <algorithm>
using namespace std;



int main(){
	
	int m;
	cin>>m;
	for(;m;m--){
		int p,y,n;
		cin>>p>>y>>n;
		int ans=0;
		for(;n;n--){
			int ri,cost;
			double ritu;
			cin>>ri>>ritu>>cost;
			int bunbo=8192,bunsi=ritu/0.0001220703125;
			 
			
			int money=p;
			if(ri){//複利
				for(int i=0;i<y;i++){
					long long A=money;
					long long B=A;
					B*=bunsi;
					B/=bunbo;
					A+=(B-cost);
					money=A;
				}
			}else{//単利
				long long B=0;
				long long A=money;
				for(int i=0;i<y;i++){
					B+=(A*bunsi/bunbo);
					A-=cost;
				}
				A+=B;
				money=A;
			}
			ans=max(ans,money);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
