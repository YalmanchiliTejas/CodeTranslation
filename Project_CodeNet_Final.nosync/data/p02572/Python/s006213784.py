import numpy
 
N = int(input())
A = list(map(int, input().split()))

ans = 0
res = [0] * N
res[0] = A[0]
for i in range(len(A)-1):
    res[i+1] = res[i] + A[i+1]

sum_A = sum(A)

for i in range(N-1):
  ans += A[i]*(sum_A-res[i])
  
mod = 10**9 + 7
print(ans%mod)