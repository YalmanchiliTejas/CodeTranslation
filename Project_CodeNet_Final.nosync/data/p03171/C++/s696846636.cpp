#include<iostream>
using namespace std;

int main()
{        
    int N;
    cin >> N;

    long long a[N];

    for (int i = 0; i < N; ++i) { 
        cin >> a[i];
    }

    long long dp[N][N]={};

    for (int i = 0; i < N; ++i) { 
        dp[i][i]=a[i];
    }

    for (int j = 1; j < N; ++j) { 
        for (int i = 0; i < N-j; ++i) { 
            long long m;
            m=a[i]-dp[i+1][i+j];
            if (m<a[i+j]-dp[i][i+j-1]){m=a[i+j]-dp[i][i+j-1];}
            dp[i][i+j]=m;
        }
    }


    cout << dp[0][N-1] << endl;
    return 0;

}