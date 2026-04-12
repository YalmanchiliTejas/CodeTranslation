#include<iostream>
#include<vector>
#include<string>

int main(){
	while(1){
	int n;
	std::cin>>n;
	if(n==0)break;
	int ans=1;
	std::vector<int> vec(6);
	for(int i=0;i<6;i++)vec[i]=i+1;
	for(int i=0;i<n;i++){
		std::string str;
		std::cin>>str;
		if(str[0]=='N'){
			int a=vec[1];
			vec[1] = vec[5];
			vec[5] = vec[4];
			vec[4] = vec[0];
			vec[0] = a;
			ans += vec[0];
		}else if(str[0] == 'E'){
			int a=vec[3];
			vec[3] = vec[5];
			vec[5] = vec[2];
			vec[2] = vec[0];
			vec[0] = a;
			ans += vec[0];
		}else if(str[0] == 'W'){
			int a=vec[0];
			vec[0] = vec[2];
			vec[2] = vec[5];
			vec[5] = vec[3];
			vec[3] = a;
			ans += vec[0];
		}else if(str[0] == 'S'){
			int a=vec[1];
			vec[1] = vec[0];
			vec[0] = vec[4];
			vec[4] = vec[5];
			vec[5] = a;
			ans += vec[0];
		}else if(str[0] == 'R'){
			int a=vec[1];
			vec[1] = vec[2];
			vec[2] = vec[4];
			vec[4] = vec[3];
			vec[3] = a;
			ans += vec[0];
		}else if(str[0] == 'L'){
			int a=vec[1];
			vec[1]=vec[3];
			vec[3]=vec[4];
			vec[4]=vec[2];
			vec[2]=a;
			ans += vec[0];
		}
	}
	std::cout<<ans<<std::endl;
	}
	return 0;
}