#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N,sum=1;
	cin>>N;
	vector<int> H(N);
    for(int i=0;i<N;++i)cin>>H[i];
	int op=H[0];
	for(int i=1;i<=N;++i){
		if(op<=H[i]){
			op=H[i];
			++sum;
		}
	}
	cout<<sum;
}