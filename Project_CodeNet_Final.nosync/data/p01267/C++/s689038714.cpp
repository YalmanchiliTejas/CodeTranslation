#include <iostream>
using namespace std;

int main(){
	
	int N,A,B,C,X;
	
	while(cin>>N>>A>>B>>C>>X,N){
		int data[101];
		for(int i=1;i<=N;i++)cin>>data[i];
		int end=-1;
		for(int i=0,j=1;i<=10000;i++){
			
			if(data[j]==X){
				j++;
			}
			if(j>N){
				end=i;
				break;
			}
			X=(A*X+B)%C;
		}
		cout<<end<<endl;
	}
	
	
	
	return 0;
}
