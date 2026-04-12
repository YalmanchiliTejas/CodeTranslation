#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;cin>>N;
	vector<int>A(N),sorted(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
		sorted[i] = A[i];
	}
	sort(sorted.begin(),sorted.end());
	
	for(int i=0;i<N;i++){
		if(A[i] >= sorted[N/2])cout<<sorted[N/2-1]<<endl;
		else cout<<sorted[N/2]<<endl;
	}
	
	
	return 0;
}