N = int(input())
S = list(map(int,input().split()))
import numpy as np
get_DP  = [[-np.inf for i in range(3)] for j in range(N)]
pass_DP = [[-np.inf for i in range(3)] for j in range(N)]
for i in range(N):
    # 常にとるやつ
    get_DP[i][0] = (pass_DP[i-1][0] if i>0 else 0) + S[i] 
    pass_DP[i][0] = get_DP[i-1][0]
    if i>0:
        get_DP[i][1] = (pass_DP[i-1][1] if i!=1 else 0) + S[i]
        pass_DP[i][1] = max(pass_DP[i-1][0], get_DP[i-1][1])
    if i>1:
        get_DP[i][2] = (pass_DP[i-1][2] if i!=2 else 0) + S[i]
        pass_DP[i][2] = max(pass_DP[i-1][1], get_DP[i-1][2])

    
print(max(get_DP[-1]+pass_DP[-1][:1+N%2]))