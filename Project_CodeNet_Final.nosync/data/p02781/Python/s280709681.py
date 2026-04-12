"""
dp[i][j][k]
i桁で非零要素をj個含み, 
「k==0」→ Nのi桁目までと一致
「k==1」→ Nのi桁目までよりも小さい
"""

N = int(input())
K = int(input())
digit = len(str(N))
N_str = str(N)

dp = [[[0]*2 for _ in range(4)] for _ in range(digit+1)]

dp[0][0][0] = 1
#配るDP
for i in range(digit): 
    for j in range(4): 
        for k in range(2):
            for d in range(10):
                ni = i+1; nj = j; nk = k
                nd = int(N_str[i])
                if d != 0: 
                    nj += 1
                if nj > K:
                    continue
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
    
                dp[ni][nj][nk] += dp[i][j][k]

ans = dp[digit][K][1]+dp[digit][K][0]
#print(dp)
print(ans)