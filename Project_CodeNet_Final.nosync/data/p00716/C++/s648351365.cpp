#include<iostream>
#include<string>
using namespace std;
int main(){
	int m;
	cin>>m;
	int a,n,y;
	bool q;
	double w;
	int e;
	for(int u=0;u<m;u++){
	cin>>a>>y>>n;
	int best=0;
	for(int i=0;i<n;i++){
		int m=a,ans=0;
		cin>>q>>w>>e;
		if(q==false){
			for(int j=0;j<y;j++){
				ans+=m*w;
				m-=e;
			}
			ans+=m;
		}
		if(q==true){
			for(int j=0;j<y;j++)
				m+=m*w-e;
			ans=m;
		}
		best=max(best,ans);
    }
	cout<<best<<endl;
	}
	return 0;
}