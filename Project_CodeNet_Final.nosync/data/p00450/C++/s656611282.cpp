#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
	int n;
	vector<int> v;//白:正,黒:負
	while(cin>>n,n){
		int c;
		v.clear();
		v.push_back(0);
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c==0){//白
				if(i&1){
					if(0<v.back())++v.back();
					else v.push_back(1);
				}
				else{
					if(0<v.back())++v.back();
					else {
						int a=-v.back();v.pop_back();
						if(v.empty())v.push_back(a+1);
						else v.back() += a+1;
					}
				}
			}
			else{//黒
				if(i&1){
					if(0<=v.back())v.push_back(-1);
					else --v.back();
				}
				else{
					if(0<v.back()){
						int a= v.back();v.pop_back();
						if(v.empty())v.push_back(-(a+1));
						else v.back() -= a+1;
					}
					else {
						--v.back();
					}
				}
			}
		}
		int ans=0;
		rep(i,v.size()){
			if(0<v[i])ans+=v[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}