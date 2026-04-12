#include<cmath>
#include<bits/stdc++.h>
#define MAX(a,b) (a>b? a:b)
#define MIN(a,b) (a>b? b:a)
#define rep(i,n) for(lint i=0;i<(lint)(n);i++)
#define repr(i,n) for(lint i=(lint)(n);i>0;--i)
#define reps(i,a,b) for(lint i=a;i<=(lint)(b);i++)
typedef long long lint;
typedef long double ld;
using namespace std;
const ld PI = acos(-1.0);

int main(){
	int K, N;
	string S;
	cin >> N >> S >> K;
	string A = S;
	rep(i,N) {
		if(A[i]!=A[K-1]) A[i] = '*';
	}
	cout << A << endl;
	return 0;
}