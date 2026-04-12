#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
long long get_ans(long long N_length,long long P_num,long long X){
	long long ans=0;;
	if(N_length==X)return P_num;
	
	if(N_length/2<=X){
		if(N_length/2+1<=X){
			ans++;
		}
		ans+=P_num/2;
		X-=N_length/2;
	}
	else{
	}
	N_length/=2;
	N_length-=1;
	P_num/=2;
	if(X!=0){
		X-=1;
		return ans + get_ans(N_length,P_num,X);
	}
	else{
		return ans;
	}
}


int main(){
	long long N,X;
	cin>>N>>X;
	long long P_num = 1;
	long long N_length=1;
	for(int i=0;i<N;i++){
		P_num=P_num*2+1;
		N_length=N_length*2+3;
	}
	cout<<get_ans(N_length,P_num,X)<<endl;
	return 0;
}
