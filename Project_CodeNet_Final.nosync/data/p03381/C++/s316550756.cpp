#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
 int n;
 cin>>n;
 long long a[n+1],b[n+1];
 for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
 sort(b+1,b+n+1,less<int>());
 for(int i=1;i<=n;i++){
 	if(a[i]<=b[n/2])cout<<b[n/2+1]<<endl;
 	else if (a[i]>=b[n/2+1])cout<<b[n/2]<<endl;
 }
 return 0;
}