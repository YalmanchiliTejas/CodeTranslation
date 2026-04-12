
import numpy as np

N = input()
K = int(input())

dp = np.zeros((len(N), 2, K+1), dtype=np.int)

for i in range(len(N)) : 
    n = int(N[i])
    if ( i == 0 ) :
        dp[i][0][0] = 1
        dp[i][0][1] = n-1
        dp[i][1][0] = 0
        dp[i][1][1] = 1
    else : 
        if n == 0 : 
            dp[i][0][0] = dp[i-1][0][0] 
            dp[i][1][0] = dp[i-1][1][0]
            for k in range(1,K+1) :
                dp[i][0][k] = dp[i-1][0][k-1]*9 + dp[i-1][0][k] 
                dp[i][1][k] = dp[i-1][1][k]
        else : 
            dp[i][0][0] = dp[i-1][0][0] + dp[i-1][1][0]
            dp[i][1][0] = 0
            for k in range(1, K+1) :
                dp[i][0][k] = dp[i-1][0][k-1]*9 + dp[i-1][0][k] + dp[i-1][1][k-1] * (n-1) + dp[i-1][1][k]
                dp[i][1][k] = dp[i-1][1][k-1]

#for k in range(K+1) :
#    print( "_" * 10 )
#    print( "K == {}".format(k) )
print( dp[len(N)-1][0][K] + dp[len(N)-1][1][K] )

