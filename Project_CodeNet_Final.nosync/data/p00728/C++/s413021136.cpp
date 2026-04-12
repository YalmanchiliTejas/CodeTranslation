#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	while(1){
		int n;
		vector<int> p;
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			int score;
			cin>>score;
			p.push_back(score);
		}
		sort(p.begin(),p.end());
		int sum=0;
		for(int j=1;j<n-1;j++){
			sum += p[j];
		}
		double ave=sum/(n-2);
		cout<<(int)ave<<endl;
	}
	return 0;
}