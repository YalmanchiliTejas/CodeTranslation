#include <iostream>
#include <string>
using namespace std;
int main(){
	string N;int K;
	cin>>N>>K;
	int len=N.length();
	if(K==1){
		printf("%d",(len-1)*9 + (N[0]-'0'));
	}
	else if(K==2){
		int sum=(len-2)*(len-1)/2*81+(N[0]-'1')*(len-1)*9;
		for(int i=1;i<len;i++){
			if(N[i]!='0'){
				sum+=(N[i]-'0')+(len-i-1)*9;
				break;
			}
		}
		printf("%d",sum);
	}
	else{
		int sum=(len-3)*(len-2)*(len-1)/6*729+(N[0]-'1')*(len-1)*(len-2)/2*81;
		for(int i=1;i<len;i++){
			if(N[i]!='0'){
				sum+=(N[i]-'1')*(len-i-1)*9+(len-i-1)*(len-i-2)/2*81;
				for(int j=i+1;j<len;j++){
					if(N[j]!='0'){
						sum+=(N[j]-'0')+(len-j-1)*9;
						break;
					}
				}
				break;
			}
		}
		printf("%d",sum);
	}
}