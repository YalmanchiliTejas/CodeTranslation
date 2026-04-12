#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define DIV 1000000007

using namespace std;

long long N, Q;
long long state[100005];
long long A[100005];
long long B[100005];

int main(){
	cin >> N >> Q;
	for(int i = 0; i < Q; i++){
		cin >> A[i] >> B[i];
		A[i]--;B[i]--;
	}
	long long pos = 0;
	state[0] = 1;
	state[1] = 1;
	for(int i = 0; i < Q; i++){
		if(pos == A[i]){
			pos = B[i];
		}else if(pos == B[i]){
			pos = A[i];
		}
		swap(state[A[i]], state[B[i]]);
		if(pos > 0){
			state[pos-1] = 1;
		}
		if(pos < N-1){
			state[pos+1] = 1;
		}
	}

	long long ans = 0;
	for(int i = 0; i < N; i++){
		//cout << "i=" << i << " state " << state[i] << endl;
		if(state[i]){
			ans++;
		}
	}
	cout << ans << endl;
}

