#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long max(long long a, long long b){
return a>b?a:b;
}

void get_opt_scoredelta(int N, long long *A){
    long long dp[N+1][N+1];
    // dp[i][j] = score difference between current player and the other player for the subsequence ai....aj
    // dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1])
    // return dp[0][N-1]
    for(int k=0; k<N; k++)
	    dp[k][k] = A[k];
    for(int p=2; p<=N; p++){
        for(int i=0; i<N-1; i++){
	    int j = i+p-1;
	    if(j < N)
		    dp[i][j] = max(A[i]-dp[i+1][j], A[j]-dp[i][j-1]);
        }
    }
    cout << dp[0][N-1] << endl;
}

int main()
{
    int N;
    cin >> N;
    long long A[N];
    for(int i=0; i < N; i++)
        cin >> A[i];
    /*for(int i=0; i<N; i++)
        cout << P[i] << " ";
    cout << endl;
    */
    get_opt_scoredelta(N, A);
    return 0;
}
