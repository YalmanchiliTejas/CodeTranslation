# -*- coding: utf-8 -*-
 
N = int(input())
A = list(map(int,input().split()))

A_sum = sum(A)

ans = 0
for i in range(N-1):
  A_sum -= A[i]
  ans += ( A[i] * A_sum )% (10**9 +7)

ans = ans % (10**9 +7)
print(ans)