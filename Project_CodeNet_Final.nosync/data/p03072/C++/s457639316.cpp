#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,inn[21],tmp_high=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>inn[i];
		if(inn[i]>=tmp_high){
			tmp_high=inn[i];sum++;
		}
	}
	cout<<sum<<endl;
 	return 0;
 }
