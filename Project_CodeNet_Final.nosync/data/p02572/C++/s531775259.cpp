#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846264338327950L

int main(void) {
	long long tmp, ans, N,wa=0;
	long long MOD = 1000000007;

	cin >> N;
	vector<long long> A(N + 5, 0),sum(N+5,0);


    wa=0;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
        tmp=tmp%MOD;
		A[i]=tmp;

        wa=wa+tmp;
        sum[i]=wa;
	}

    ans=0;
    for(int i=0;i<N;i++){
        tmp=sum[N]-sum[i];
        tmp=tmp%MOD;
        tmp=A[i]*tmp;
        tmp=tmp%MOD;
        ans = ans+tmp;
        ans=ans%MOD;
    }




	cout << ans << endl;


	return 0;
}

