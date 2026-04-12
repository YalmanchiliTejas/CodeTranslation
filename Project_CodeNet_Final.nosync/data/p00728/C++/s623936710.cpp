#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int N,n,sum;
	vector<int> point;
	while(1){
		cin>>N;
		if(N==0) break;
		sum=0;

		while(!point.empty()){
			point.pop_back();
		}

		for(int i=0;i<N;i++){
			cin>>n;
			point.push_back(n);
		}

		sort(point.begin(),point.end());

		for(int i=1;i<point.size()-1;i++){
			sum+=point[i];
		}
		cout<<sum/(point.size()-2)<<endl;
	}
	return 0;
}	