#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
 
using namespace std;

int arr [200000];
long long arr2 [200000];
long long arr3[200000];
long long cul(int c, int b){
	
	if(c==0)return arr[0];
	if(c==1)return max(arr[0],arr[1]);
	if(c==2)return max(max(arr[0],arr[1]),arr[2]);
	if(c%2!=0)return arr3[c];
	return max(max(arr3[c-1],arr2[c-2]),arr[c]+cul(c-2,b));
	
}
	
	
	
int main()
{ 
	for(int i=0;i<200000;i++){arr[i]=0;arr2[i]=0;}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	arr2[0]=arr[0];
	for(int i=2;i<n;i=i+2)arr2[i]=arr2[i-2]+arr[i];
	arr3[1]=max(arr[0],arr[1]);
	for(int i=3;i<n;i=i+2)arr3[i]=max(arr3[i-2]+arr[i],arr2[i-1]);
	cout<<cul(n-1,n)<<endl;
	return 0;
}
	