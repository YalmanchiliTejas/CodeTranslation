import math

def makelist(n, m):
    return [[0 for _ in range(m)] for _ in range(n)]

N = input()
l = len(N)
K = int(input())

dpSt = makelist(l, K+1)
dpCa = makelist(l, K+1)

init = int(N[0])
dpSt[0][1] = 1
dpCa[0][0] = 1
dpCa[0][1] = init - 1

for i in range(1, l):
    now = int(N[i])

    if now == 0:
        for k in range(K+1):
            dpSt[i][k] = dpSt[i-1][k]
            dpCa[i][k] = dpCa[i-1][k]
        for k in range(1, K+1):
            dpCa[i][k] += dpCa[i-1][k-1] * 9
    else:
        for k in range(1, K+1):
            dpSt[i][k] = dpSt[i-1][k-1]

        for k in range(K+1):
            dpCa[i][k] += dpSt[i-1][k]
        for k in range(1, K+1):
            dpCa[i][k] += dpSt[i-1][k-1] * max(0, now-1)


        for k in range(K+1):
            dpCa[i][k] += dpCa[i-1][k]
        for k in range(1, K+1):
            dpCa[i][k] += dpCa[i-1][k-1] * 9

ans = dpSt[l-1][K] + dpCa[l-1][K]
print(ans)
