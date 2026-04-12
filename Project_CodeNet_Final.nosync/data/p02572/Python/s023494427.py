N = int(input())
A = list(map(int,input().split()))

res = 0
mod = 10**9 + 7

sum_A = 0
for i in range(N):
  sum_A += A[i]

for i in range(N-1):
  sum_A -= A[i]
  res += sum_A * A[i]
  
print(res % mod)