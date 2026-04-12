import sys
n = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
ans = 0
# for i in range(n-1):
#     for j in range(i+1,n):
#         ans += A[i]*A[j]
#         ans %= mod
sum = 0
for i in A:
    sum += i

ans = sum * sum
for j in A:
    ans -= j * j
ans //= 2    
ans %= mod
# ans = 0
# for i in range(n):
#     ans += A[i] * (sum-A[i])
#     ans %= mod
# ans //= 2
print(ans)

