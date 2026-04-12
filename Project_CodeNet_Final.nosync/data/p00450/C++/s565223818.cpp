#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int head=0;
int C[100001]={0};
int S[100001]={0};
int E[100001]={0};


void draw(){
	for(int i=0;i<=head;i++){
		cout<<"("<<C[i]<<","<<S[i]<<"-"<<E[i]<<") ";
	}
	cout<<endl;
}

int main(){
	
	int n;
	while(cin>>n,n){
		head=0;
		int t;
		cin>>t;
		S[0]=E[0]=1;
		C[0]=t;
		//cout<<1<<","<<t<<" : ";
		//draw();
		for(int i=2;i<=n;i++){
			int t;
			cin>>t;
			if(i%2==1){
				if(C[head]==t){
					E[head]++;
				}
				else{
					head++;
					C[head]=t;
					S[head]=E[head]=E[head-1]+1;
				}
			}
			else{
				if(C[head]==t){
					E[head]++;
				}
				else{
					C[head]=t;
					E[head]++;
					while(head>0){
						if(C[head]!=C[head-1])break;
						E[head-1]=E[head];
						head--;
					}
				}
			}
			//cout<<i<<","<<t<<" : ";
			//draw();
		}
		int ans=0;
		for(int i=0;i<=head;i++){
			if(C[i]==0){
				ans+=(E[i]-S[i]+1);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
