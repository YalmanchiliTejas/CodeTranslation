#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
	LL k,a,b;
	while(cin>>k>>a>>b){
		//1次达标情况 
		if(a>=k)
			cout<<1<<endl;		
		//不可能达标情况 
		else if(a<=b){
			cout<<-1<<endl;
		}
		//一般情况 
		else{
			LL n,m;
			n=k/(a-b);
			for(int i=a;i>=0;i--){
				if((a-b)*(n-i)+a>=k){
					m=2*(n-i)+1;
					break;
				}			
			}
			cout<<m<<endl;
		}		
	}
	return 0;
}