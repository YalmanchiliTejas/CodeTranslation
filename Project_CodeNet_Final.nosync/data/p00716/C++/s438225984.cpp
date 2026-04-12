#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF (1<<29)



int main(){
	int m;
	cin>>m;
	while(m--){
		int s,y,n;
		cin>>s>>y>>n;
		int ans=-1;
		while(n--){
			int ss=s;
			int a,tesu;
			double nenri;
			cin>>a>>nenri>>tesu;
			if(a==0){
				int risi=0;
				for(int i=0;i<y;i++){
					risi += (int)(ss*nenri);
					ss -= tesu;
				}
				ans = max(ans,ss+risi);
			}else{
				for(int i=0;i<y;i++){
					ss += (int)(ss*nenri)-tesu;
				}
				ans = max(ans,ss);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}