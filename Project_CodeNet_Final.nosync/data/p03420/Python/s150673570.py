import math
N, K = map(int, input().split())
if K == 0:
    ans = N*N
else:
    ans = 0
    j = 1
    for i in range(K+1, N+1):
        mod = N % i
        x = N//i
        ans += x*j
        if mod>=K:
            ans+=mod-K+1
        j += 1
print(ans)
