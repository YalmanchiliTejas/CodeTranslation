#include<iostream>
using namespace std;
static const int MAX_N=10e5;
int A[MAX_N+1];
int main(void){
	int N;
		cin >> N;
	for(int i=1;i<=N;i++)
		cin >> A[i];
	int ans=0;
	for(int i=1;i<=N;i++){
		if(A[i]-A[i-1]>=0){
			ans++;
		}else{
			A[i]=A[i-1];
		}
	}
	cout << ans << endl;
	return 0;
}