#from fractions import gcd
#mod = 10 ** 9 + 7
#N = int(input())
#a = list(map(int,input().split()))
#a,b,c = map(int,input().split())
#ans = [0] * N
#math.ceilで切り上げ
#dp = [[0] * 4 for i in range(3)] #2次元配列初期化
#dp = [[[0] * 2 for i in range(3)] for j in range(5)]

import math
import string

def intinput():
    return int(input())

def listintinput():
    return list(map(int,input().split()))

def splitintinput():
    return map(int,input().split())

N = str(intinput())
K = intinput()
s = len(str(N))
dp = [[[0] * 2 for i in range(4)] for j in range(s+1)]
dp[0][0][0] = 1
for h in range(1,s+1):
    dp[h][0][1] = 1
    for i in range(1,4):
        for j in range(0,2):
            if j == 1:      
                for k in range(0,10):
                    if int(N[h-1]) == 0:
                        dp[h][i][j] += dp[h-1][i][1] + dp[h-1][i-1][1]*9
                        break
                    if int(N[h-1]) > k:
                        if k == 0:
                            dp[h][i][j] += dp[h-1][i][0] + dp[h-1][i][1]
                        if k != 0:
                            dp[h][i][j] += dp[h-1][i-1][0] + dp[h-1][i-1][1]
                    if int(N[h-1]) <= k:
                        dp[h][i][j] += dp[h-1][i-1][1]
            if j == 0:
                if int(N[h-1]) == 0:
                    dp[h][i][j] += dp[h-1][i][0]
                else:
                    dp[h][i][j] += dp[h-1][i-1][0]

print(dp[s][K][0]+dp[s][K][1])
            
                
                
 

