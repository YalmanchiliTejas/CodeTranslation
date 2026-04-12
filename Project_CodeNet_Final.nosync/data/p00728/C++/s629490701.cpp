#include<iostream>
using namespace std;

int main()
{
	int n,m,i;
	int ave[1000]={0};

	m=0;
	while(1){
		int point[100]={0};
		int min=1000;
		int max=0;
		cin>>n;
		if(n==0) break;
		for(i=0;i<n;i++){
			cin>>point[i];
			if(point[i]>max) max=point[i];
			if(point[i]<min) min=point[i];
			ave[m]+=point[i];
		}
//		cout<<"debug "<<ave[m]<<endl;
//		cout<<max<<" "<<min<<endl;
		ave[m]=(ave[m]-max-min)/(n-2);
		m++;
	}
	for(i=0;i<m;i++){
		cout<<ave[i]<<endl;
	}
}