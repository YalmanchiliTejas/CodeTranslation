#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> A(n);
	for(int i = 0; n > i; i++){
		cin>>A[i];
	}
	int mx = 0;
	for(int i = 0; n > i; i++){
		if(mx < i){
			cout << "no" << endl;
			return 0;
		}
		mx = max(mx,i+A[i]/10);
	}
	reverse(A.begin(),A.end());
	mx = 0;
	for(int i = 0; n > i; i++){
		if(mx < i){
			cout << "no" << endl;
			return 0;
		}
		mx = max(mx,i+A[i]/10);
	}
	cout << "yes" << endl;
}
