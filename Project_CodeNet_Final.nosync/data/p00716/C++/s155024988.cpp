#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	
	int m;
	cin>>m;
	int y,n;
	long long int A;
	while(m>0){
		long long int max=0;
		cin>>A>>y>>n;
		for(int i=0;i<n;i++){
			int t,h;
			double x;
			long long int a=A;
			long long int B=0,s=0;
			cin>>t>>x>>h;
			for(int j=0;j<y;j++){
				if(t!=0){
					B=a*x;
					a=a+B-h;
				}
				else{
					B=a*x;
					a=a-h;
					s+=B;
				}
			}
			if(max<a+s)
				max=a+s;
	}
		cout<<max<<endl;
		m--;
	}
	
}