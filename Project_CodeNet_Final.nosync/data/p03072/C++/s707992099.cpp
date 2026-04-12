#include<iostream>
using namespace std;

int main(){
	int N;
	int A[110];
	int tmp = 0;
	int ans = 1;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> A[i];
	}
	tmp = A[0];
	for(int i=1; i<N; i++){
		if(tmp<=A[i]){
			ans++;
			tmp = A[i];
		}
	}
		cout << ans << endl;
	return 0;
}
	 