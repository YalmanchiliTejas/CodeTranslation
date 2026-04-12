#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		int a=10000,b=-1,sum=0;
		for(int i=0;i<n;i++){
			int s;
			cin>>s;
			sum+=s;
			a=min(a,s);
			b=max(b,s);
		}
		cout<<(sum-a-b)/(n-2)<<endl;
	}
}