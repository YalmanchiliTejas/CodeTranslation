S = list(map(int,list(input())))
K = int(input())
from itertools import groupby, accumulate, product, permutations, combinations
def solve(S,K):
    ans = 0
    n = len(S)
    dp1 = [[0]*5 for _ in range(n)]
    dp0 = [[0]*5 for _ in range(n)]
    dp0[0][1] = 1
    dp1[0][0] = 1
    dp1[0][1] = S[0]-1
    for i in range(1,n):
        for j in range(4):
            dp1[i][j] = dp1[i-1][j]+dp1[i-1][j-1]*9
            if S[i]==0:
                dp0[i][j] = dp0[i-1][j]
            else:
                dp0[i][j] = dp0[i-1][j-1]
                dp1[i][j] += dp0[i-1][j-1]*(S[i]-1)+dp0[i-1][j]
    ans = dp1[n-1][K]+dp0[n-1][K]
    return ans
print(solve(S,K))