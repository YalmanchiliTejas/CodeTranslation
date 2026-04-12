#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	int n;
	int *tokuten;
	int maxi=0,mini=1000;
	int goukei=0,cnt=0;
	int *heikin=new int[100];
	while(1){
		cin>>n;
		int i=0;
		if(n==0)
			break;

		tokuten=new int[n];
		maxi=0;
		mini=1000;
		for(i=0;i<n;i++){
			cin>>tokuten[i];
			maxi=max(maxi,tokuten[i]);
			mini=min(mini,tokuten[i]);
			goukei+=tokuten[i];
		}
		
		
		goukei=goukei-(mini+maxi);
		goukei=goukei/(n-2);
		heikin[cnt]=goukei;
		goukei=0;
		cnt++;
		delete[] tokuten;
		
	}
	for(int j=0;j<cnt;j++)
		cout<<heikin[j]<<endl;
	delete[] heikin;
	
	return 0;
}