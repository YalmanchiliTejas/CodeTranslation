#include<iostream>
#include<vector>

int main(){
	while(1){
		int n,score=0;
		std::cin>>n;
		if(n==0)break;
		std::vector<int>v(n);
		for(int i=0;i<n;i++)std::cin>>v[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<n-1;j++){
				if(v[j]>v[j+1]){
					v[j]^=v[j+1];
					v[j+1]^=v[j];
					v[j]^=v[j+1];
				}
			}
		}
		for(int i=1;i<n-1;i++)score+=v[i];
		std::cout<<score/(n-2)<<std::endl;
	}
	return 0;
}