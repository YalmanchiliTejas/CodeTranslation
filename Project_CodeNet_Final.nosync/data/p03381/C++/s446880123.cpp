#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long LL;
int main(int argc, char* argv[])
{
	int N;
	cin>>N;
	int i;
	vector<LL> A(N),B(N);
	for (i=0;i<N;i++){
		cin>>A[i];
		B[i]=A[i];
	}
	int l=N/2-1;
	sort(B.begin(),B.end(),greater<LL>());
	int j=0;
	for (i=0;i<N;i++){
		if (B[l]>A[i]){
			cout<<B[l]<<endl;
		}else{
			cout<<B[l+1]<<endl;
		}
	}
	return 0;
}