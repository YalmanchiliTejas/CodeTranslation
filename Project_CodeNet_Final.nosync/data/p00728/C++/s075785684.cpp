#include<iostream>
#include<list>
using namespace std;

int main(){
	while(true){
		int n,sum=0;
		list<int> score; 
		cin>>n;
		if(n==0)break;
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			score.push_back(tmp);
		}
		score.sort();
		score.pop_back();
		score.pop_front();
		for(list<int>::iterator it=score.begin();it!=score.end();++it)sum+=*it;
		cout<<sum/(n-2)<<endl;
	}
	return 0;
}