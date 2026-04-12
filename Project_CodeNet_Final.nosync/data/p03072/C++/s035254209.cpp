


#include <bits/stdc++.h>


using namespace std;

int main(){

	int N;
	cin>>N;
	vector<int> m;
	
	for(int i=0;i<N;i++){
		int h;
		cin>>h;
		m.push_back(h);
	}
	
	int count=1;
	
	for(int i=1;i<m.size();i++){
		bool ind=false;
		for(int j=i-1;j>=0;j--){
			if(m[j]>m[i]){
				ind=true;
				break;
			}
			
		}
		if(ind){
			continue;
		}
		else{
			count=count+1;
		}
		
	}
	
	cout<<count<<endl;
	
		
	


	return 0;
}


