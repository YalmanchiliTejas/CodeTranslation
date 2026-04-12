#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		int point[100],sum=0;
		for(int i=0,s;i<n;++i){
			cin>>s;
			point[i]=s;
		}
		for(int i=0,s;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(point[i]>point[j])swap(point[i],point[j]);
			}
		}
		for(int i=1;i<n-1;++i){
			sum+=point[i];
		}
		cout<<(sum/(n-2))<<"\n";
	}
	return 0;
}