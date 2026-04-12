#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int n,s;

int main(){
    while(cin>>n&&n){
	int sum=0,M=0,m=1000;
	rep(i,n){cin>>s;sum+=s;if(s>M)M=s;if(s<m)m=s;}
	cout<<(sum-M-m)/(n-2)<<endl;
    }
}