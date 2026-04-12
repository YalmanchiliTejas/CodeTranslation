#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(n!=0){
		cin>>n;
		if(n==0){
			break;
		}
		vector<int> score;
		int hoge;
		for(int i=0;i<n;i++){
			cin>>hoge;
			score.push_back(hoge);
		}
		sort(score.begin(), score.end());
		int sum=0;
		for(int i=1;i<n-1;i++){
			sum += score[i];
		}
		cout<<sum/(n-2)<<endl;
	}
}