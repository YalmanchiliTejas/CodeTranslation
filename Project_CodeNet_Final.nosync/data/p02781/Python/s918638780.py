N=int(input())
K=int(input())

def dp(N,K):
    keta = len(str(N))
    table = [[[0,0] for i in range(K+1)] for j in range(keta+1)]
    table[0][0][0]=1
    for i in range(keta):
        for j in range(K+1):
            for k in range(2):
                enable_num = int(str(N)[i]) if k==0 else 9
                for x in range(enable_num+1):
                    if x==0:
                        next_j = j
                    else:
                        next_j = j + 1
                    if next_j > K: continue
                    if k == 0 and x == enable_num:
                        next_k = 0
                    else:
                        next_k = 1
                    table[i+1][next_j][next_k]+=table[i][j][k]
    return table[keta][K][0] + table[keta][K][1]
print(dp(N,K))