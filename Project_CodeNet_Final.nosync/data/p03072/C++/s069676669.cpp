#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[25];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=1;
	for(int i=1;i<n;i++){
		int f=1;
		for(int j=0;j<i;j++){
			if(a[j]>a[i]){
				f=0;
				break;
			}
		}
		if(f==1) sum++;
	}
	cout<<sum<<endl;
}