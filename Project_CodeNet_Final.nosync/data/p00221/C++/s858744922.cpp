#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){

	//ply.erase(find(ply.begin(),ply.end(),3));
	int m,n;
	while(cin>>n>>m&&!(n==0&&m==0)){
		vector<int> ply;
		for(int i = 0; i < n; i++)
			ply.push_back(i);
		int tern=0;
		bool f=false;
		for(int i = 1; i <= m; i++){
			string str;
			cin>>str;
			if(ply.size()==1)
				continue;
			if(i%3==0&i%5==0){
				if(str=="FizzBuzz"){
					tern++;
					tern%=ply.size();
				}
				else{
					ply.erase(find(ply.begin(),ply.end(),ply[tern]));
					if(tern==ply.size()){
						tern=0;
					}
				}
			}
			else if(i%3==0){
				if(str=="Fizz"){
					tern++;
					tern%=ply.size();
				}
				else{
					ply.erase(find(ply.begin(),ply.end(),ply[tern]));
					if(tern==ply.size()){
						tern=0;
					}
				}
			}
			else if(i%5==0){
				if(str=="Buzz"){
					tern++;
					tern%=ply.size();
				}
				else{
					ply.erase(find(ply.begin(),ply.end(),ply[tern]));
					if(tern==ply.size()){
						tern=0;
					}
				}
			}
			else{
				int num=atoi(str.c_str());
				if(num==i){
					tern++;
					tern%=ply.size();
				}
				else{
					ply.erase(find(ply.begin(),ply.end(),ply[tern]));
					if(tern==ply.size()){
						tern=0;
					}
				}
			}
		}

		for(int i = 0; i < ply.size(); i++){
			cout<<ply[i]+1;
			if(i!=ply.size()-1)
				cout<<" ";
			else
				cout<<endl;
		}
	}

	return 0;
}