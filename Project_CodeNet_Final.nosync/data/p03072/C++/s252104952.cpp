#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	int sum=1;
	vector<int> v(N);
	for(int i=0; i<N; i++){	
		cin>>v[i];
	}
	int sub=v[0];
	for(int i=0; i<N-1; i++){	
	if(sub<=v[i+1]){
		sum++;
		sub=v[i+1];
	}
	
	
}cout<<sum<<endl;
}