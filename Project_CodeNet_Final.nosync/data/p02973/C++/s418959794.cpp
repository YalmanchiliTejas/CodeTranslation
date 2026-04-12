#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>

#define LLI long long int

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];

	multiset<int>B;
	for(int i=N-1;i>=0;i--){
		if(B.upper_bound(A[i])==B.end()){
			B.insert(A[i]);
		}else{
			B.erase(B.upper_bound(A[i]));
			B.insert(A[i]);
		}
	}
	
	cout<<B.size()<<endl;

	return 0;
}

