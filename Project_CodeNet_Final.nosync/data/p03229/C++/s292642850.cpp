#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> A;


int solve(){
	vector<int> ansv;
	long long ans=0;

	sort(A.begin(),A.end());

	int small = 1;
	int large = N-2;

	ansv.push_back(A[0]);
	ansv.push_back(A[N-1]);

	bool flag = true;
	for(int i=0; i<N/2-1; i++){
		if(flag){
			ansv.push_back(A[small]);
			ansv.insert(ansv.begin(),A[large]);
			small++;large--; 
		}else{
			ansv.insert(ansv.begin(),A[small]);
			ansv.push_back(A[large]);	
			small++; large--;		
		}
		flag ^= true;
	}

	if(N%2==1) {
		if(abs(ansv[0]-A[N/2]) > abs(ansv[ansv.size()-1]-A[N/2])) ansv.insert(ansv.begin(), A[N/2]);
		else ansv.push_back(A[N/2]);
	}

	for(int i=0;i<N-1;i++){
		ans += abs(ansv[i]-ansv[i+1]);
	}

	// for(int i=0; i<N; i++){
	// 	cout << ansv[i] << " ";
	// }

	cout << ans << endl;
	return 0;
}


int main(){
	cin >> N;
	A.resize(N);
	for(int i=0;i<N;i++){
		cin >> A[i];
	}

	solve();
	return 0;
}
