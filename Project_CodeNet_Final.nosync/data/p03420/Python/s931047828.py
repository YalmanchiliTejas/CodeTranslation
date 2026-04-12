# -*- coding: utf-8 -*-
def inpl(): return map(int, input().split())
N, K = inpl()

if K == 0:
    print(N*N)
    exit()

ans = 0
for b in range(K+1, N+1):
    d, m = divmod(N, b)
    ans += d*(b-K)
    ans += max(0, m+1-K)

print(ans)