from collections import defaultdict
INF = 10 ** 15
N = int(input())
A = list(map(int,input().split()))
dp_take = defaultdict(lambda: -INF)
dp_not = defaultdict(lambda: -INF)
dp_take[(0,0)] = 0
dp_not[(0,0)] = 0

for i in range(N):
    for j in range((i + 1) // 2 - 1, (i + 2) // 2 + 1):
        if j > 0:
            dp_take[(i+1, j)] = max(dp_take[(i+1, j)], dp_not[(i, j-1)] + A[i])
        dp_not[(i+1, j)] = max(dp_not[(i, j)], dp_take[(i, j)])

print(max(dp_take[(N, N//2)], dp_not[(N, N//2)]))