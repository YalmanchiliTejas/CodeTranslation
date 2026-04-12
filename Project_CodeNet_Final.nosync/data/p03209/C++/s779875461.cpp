#include<iostream>
long N,X,p,i;
int main(){
	std::cin>>N>>X;
	for(i=(1LL<<N/2)*(1<<(N+3>>1));i;i>>=1,--X){
		if(X+1>=i){
			p|=i>>1;
			X-=i-2;
		}
	}
	std::cout<<p;
	return 0;
}
