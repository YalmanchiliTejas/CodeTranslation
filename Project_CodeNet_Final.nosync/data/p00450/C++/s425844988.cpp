#include<iostream>
#include<vector>
using namespace std;



int main(){
	int n;
	while(cin>>n &&n){
		vector<int> black;
		vector<int> white;
		int now;
		cin>>now;
		if(now==1)black.push_back(1);
		else white.push_back(1);
		for(int i=2;i<=n;i++){
			int in;
			cin>>in;
			
			if(i%2==0){
				if(in==now){
					if(in)black[black.size()-1]++;
					else white[white.size()-1]++;
					
				}
				else {
				
					if(in){
						if(!black.empty())black[black.size()-1]+=white[white.size()-1]+1;
						else black.push_back(white[white.size()-1]+1);
						white.pop_back();
					}
					else{
						if(!white.empty())white[white.size()-1]+=black[black.size()-1]+1;
						else white.push_back(black[black.size()-1]+1);
						black.pop_back();
					}
				}
				
			}
			else{
				if(in==now){
					if(in)black[black.size()-1]++;
					else white[white.size()-1]++;
				}
				else{
					if(in)black.push_back(1);
					else white.push_back(1);
				}
			}
			
			now=in;
		}
		int ans=0;
		for(int i=0;i<white.size();i++)ans+=white[i];
		cout<<ans<<endl;
		
	}
}