#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long N,arr[55];
	long long count=0;


	cin>>N;
	for(int i=0; i<N; i++) {
		cin>>arr[i];
	}

	while(true) {
		sort(arr,arr+N);
		if(arr[N-1]<N)
			break;

		for(int i=0; i<N-1; i++) {
			arr[i]+=arr[N-1]/N;
		}
		count+=arr[N-1]/N;
		arr[N-1]%=N;
	}
	cout<<count<<endl;

	return 0;
}