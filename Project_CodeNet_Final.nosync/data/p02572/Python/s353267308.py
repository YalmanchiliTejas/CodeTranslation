#ABC177 C
N = int(input())
A = list(map(int,input().split()))
ans = 0
Asum = sum(A)

for i in range(0,N-1):
  Asum -= A[i]
  ans += A[i] * Asum

print(ans % (10**9 + 7))