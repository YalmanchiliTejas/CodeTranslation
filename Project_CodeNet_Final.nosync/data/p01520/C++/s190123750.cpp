#include<iostream>
#include<vector>

using namespace std;

int main(){

	int N,T,E;
	vector<int> ti;
	int x;

	cin>>N>>T>>E;

	for(int i=0;i<N;i++){
		cin>>x;
		ti.push_back(x);
	}

	for(int i=T-E;i<=T+E;i++){
		for(int j=0;j<ti.size();j++){
			if(i%ti[j]==0){
				cout<<j+1<<endl;
				return 0;
			}
		}
	}

	cout<<"-1"<<endl;

	return 0;
}