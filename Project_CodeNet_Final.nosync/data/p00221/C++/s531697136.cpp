#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int m,n;
	while(cin>>m>>n,m){
		int num=m;
		int flag[1000]={0};
		int data[1000][2];
		for(int i=0;i<m;i++){
			data[i][0]=i-1;
			data[i][1]=i+1;
		}
		data[0][0]=m-1;
		data[m-1][1]=0;
		string s;
		int turn=0;
		for(int i=0;i<n;i++){
			cin>>s;
			int l=1;
			if((i+1)%15==0){
				if(s!="FizzBuzz")l=0;
			}else if((i+1)%3==0){
				if(s!="Fizz")l=0;
			}else if((i+1)%5==0){
				if(s!="Buzz")l=0;
			}else{
				ostringstream os;
				os<<(i+1);
				if(s!=os.str())l=0;
			}
			
			if(l==0){
				
				if(num>1){
					num--;
					flag[turn]=1;
					int bef=data[turn][0];
					int aft=data[turn][1];
					
					data[bef][1]=aft;
					data[aft][0]=bef;
				}
			}
			turn=data[turn][1];
		}
		int k=0;
		for(int i=0;i<m;i++){
			if(flag[i]==0){
				if(k)cout<<" ";
				cout<<i+1;
				k=1;
			}
		}
		cout<<endl;
		
	}
	
	
}
