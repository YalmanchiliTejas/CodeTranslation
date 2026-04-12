#include<bits/stdc++.h>
using namespace std;
int t[100000];
int main(void)
{
	int n;
	int max;
	int i,j;
	int sum;
	int cnt,cnt2,MC[1000];
	cin>>n;
	max=-1;
	for(i=0;i<n;i++){
		cin>>t[i];
		if(max<t[i]) max=t[i];
	}
	cnt=1; cnt2=0;
	while(cnt!=max){
		if(max%cnt==0){
			MC[cnt2]=cnt;
			cnt2++;
		}
		cnt++;
	}
	MC[cnt2]=max;
	cnt2++;
/*	cout<<MC[cnt2]<<endl;
	for(i=0;i<cnt2;i++) cout<<MC[i]<<" ";
	cout<<endl;*/
	
	sum=0;
	for(i=0;i<n;i++){
		if(max%t[i]!=0){
			for(j=0;j<cnt2;j++){
				if(MC[j]>t[i]){
					sum+=MC[j]-t[i];
					break;
				}
			}
		}
	}
	
	cout<<sum<<endl;
	
	return 0;
}
