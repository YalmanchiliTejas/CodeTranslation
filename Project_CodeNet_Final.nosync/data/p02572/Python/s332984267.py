N = int(input())
A = list(map(int,input().split()))
mod = 10**9 + 7

sum_A = sum(A)
ans = 0

for i in range(N):
  sum_A -= A[i]
  ans += (A[i]*sum_A)

print(ans%mod)