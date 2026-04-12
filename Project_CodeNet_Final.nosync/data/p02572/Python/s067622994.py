N = int(input())
A = list(map(int,input().split()))

sum_A = sum(A)
mod = 10**9+7
ans = 0
for i in range(N-1):
  a = A[i]
  sum_A-=a
  ans+=a*sum_A
print(ans%mod)