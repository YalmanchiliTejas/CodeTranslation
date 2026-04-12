import math
import pprint
#N以下の0以外のK種類の数が含まれている数字列
N = int(input())
K = int(input())


N_d = int(math.log10(N))


def N_n(n):
    return int(N//(10**(n))%(10))

dp = [[[-1]*2 for i in range(K+2)] for i in range(int(math.log10(N))+2)]




def rec(i,j,t):
    if j < 0 :
        return 0

    if dp[i][j][t]!=-1:
        return dp[i][j][t]
    
    nnn = N_n(i)
    #print("start",i,j,t, nnn)
    if i == 0:
        if j == 0:
            dp[i][j][t] = 1
        elif j == 1:
            if t:
                dp[i][j][t] = nnn
            else:
                dp[i][j][t] = 9
        else:
            dp[i][j][t] = 0
    else:
        if t:
            if nnn==0:
                dp[i][j][t] = rec(i-1,j,True)
            else:
                dp[i][j][t] = rec(i-1,j,False) + (rec(i-1,j-1,False) * (nnn-1)) + (rec(i-1,j-1,True))
        else:
            dp[i][j][t] = rec(i-1,j,False) + (rec(i-1,j-1,False) * 9)
    return dp[i][j][t]

print(rec(N_d,K,True))
#pprint.pprint(dp)