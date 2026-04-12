#include <bits/stdc++.h>
using namespace std;
int N, top, A[200001], dec_len[200001];
int main(){
	cin >> N;
	for(int i=N; i>=1; --i) cin >> A[i];
	for(int i=1; i<=N; ++i) {
		if(A[i]>=dec_len[top]){
			dec_len[++top]=A[i];
		}else {
			dec_len[upper_bound(dec_len+1,dec_len+top+1,A[i])-dec_len]=A[i];
		}
	}
	cout << top << endl;
	return 0;
}