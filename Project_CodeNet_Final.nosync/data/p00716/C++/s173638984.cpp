#include<iostream>
#include<algorithm>

using namespace std;
int main(){

	int m;
	cin>>m;
	while(m--){
		int P;
		cin>>P;
		int y;
		cin>>y;
		int n;
		cin>>n;
		int ans = 0;
		while(n--){
			bool isH;
			double r;
			int c;
			cin>>isH>>r>>c;
			int A = P;
			int Q = 0;
			for(int i = 0;i < y;i++){
				if(isH){
					int B = A * r;
					A += B - c;
				}
				else{
					int B = A * r;
					Q += B;
					A -= c;
				}
			}
			ans = max(ans,A + Q);
		}
		cout<<ans<<endl;
	}

}