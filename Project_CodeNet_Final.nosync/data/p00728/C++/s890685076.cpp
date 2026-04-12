#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF (1<<29)

int main(){
	int n,s,mi,ma,t;
	while(cin>>n&&n){
		mi=INF;ma=-1;
		s=0;
		for(int i=0;i<n;i++){
			cin>>t;
			s+=t;
			mi=min(mi,t);
			ma=max(ma,t);
		}
		cout<<(s-ma-mi)/(n-2)<<endl;
	}
	return 0;
}