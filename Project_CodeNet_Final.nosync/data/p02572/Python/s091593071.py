N = int(input())
A = list(map(int,input().split()))
MOD = 10**9+7

cumsum = [A[0]]
for i in range(1,N):
  cumsum.append(A[i]+cumsum[i-1])

ans = 0
for i in range(N):
  ans += (A[i]*(cumsum[-1]-cumsum[i]))%MOD
  ans %= MOD

print(ans)