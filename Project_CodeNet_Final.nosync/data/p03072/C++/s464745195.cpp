#include<bits/stdc++.h>
using namespace std;


int A[1000];
int main(){
	int n,a,ans=1;
	cin >> n;
	for(int i=0;i<n;i++) cin >> A[i];
	
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(A[j]>A[i]) goto aa;
		}
		ans++;
		aa:;
	}
	cout << ans << endl;
	return 0;
}