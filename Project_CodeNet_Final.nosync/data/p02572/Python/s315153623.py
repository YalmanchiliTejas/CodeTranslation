N = int(input())
MOD = 1000000007
A =  list(map(int,input().split()))
cum = [0]*(N+1)
for i in range(N):
    cum[i+1] = cum[i] + A[i]
    cum[i+1] %= MOD

ans = 0

for i in range(N-1):
    ans += A[i] * (cum[N] - cum[i+1])
    ans %= MOD

print(ans)