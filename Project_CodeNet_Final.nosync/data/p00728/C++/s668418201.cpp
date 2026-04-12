#include<iostream>

using namespace std;

int main(){
	int n,s,inputNum,minNum,maxNum;
	
	while(cin>>n,n){
		minNum=(int)1e+8;
		s=maxNum=0;
		
		for(int i=0;i<n;i++){
			cin>>inputNum;
			s+=inputNum;
			if(inputNum<minNum){
				minNum=inputNum;
			}
			if(inputNum>maxNum){
				maxNum=inputNum;
			}
		}
		
		s=s-maxNum-minNum;
		s=s/(n-2);
		
		cout<<s<<endl;
	}
}