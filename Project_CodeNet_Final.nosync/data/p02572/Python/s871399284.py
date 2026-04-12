# -*- coding: utf-8 -*-
N = int(input())
A = list(map(int, input().split()))
p = 10**9 + 7

total = 0
for i in range(N):
  total += A[i]
  total = total % p

total_tmp = 0
ans = 0
for i in range(N):
  total_tmp += A[i]
  total_tmp = total_tmp % p
  
  ans += A[i] * (total-total_tmp)
  ans = ans % p
print(ans)