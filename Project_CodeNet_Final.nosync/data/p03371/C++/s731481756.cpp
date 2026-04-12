#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//abc095_c
//解説参考
int main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	

	int z=max(x,y);
	int min=c*2*z;
	for(int i=z-1;i>=0;i--){
		int sum=c*2*i+a*max(0,x-i)+b*max(0,y-i);
		if(min>sum) min=sum;
	}
	
	
	cout<<min<<endl;
	
	return 0;
}