#include <iostream>
#include<math.h>
using namespace std;

int main() {
	long long int m,n;
long long int ans=0;
cin>>m>>n;
for(int i=n+1;i<=m;i++){
int a=fmaxl(0,n-1-m%i);
//cout<<a<<" ";
if(n!=0){
ans+=m-((m/i+1)*n-a-1);
}
else{
ans+=m;
}
//cout<<ans<<endl;
}
cout<<ans;
	return 0;
}