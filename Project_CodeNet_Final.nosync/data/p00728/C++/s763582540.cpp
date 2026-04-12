#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)(n);i++)

int main() {
	int N;
	while(cin>>N && N>0){
		int A[N];
		rep(i,N) cin >> A[i];
		int M = 0;
		rep(i,N){
			if (M<A[i]){
				M=A[i];
			}			
		}
		int m = 10000000;
		rep(i,N){
			if(m>A[i]){
				m=A[i];
			}
		}
		int sum =0;
		rep(i,N){
			sum += A[i];
		}
		
		sum = sum - M - m;
		int ave = sum/( N - 2);
		cout << ave<<endl;
	}
	return 0;
}

