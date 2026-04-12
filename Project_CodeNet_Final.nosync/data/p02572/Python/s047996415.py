N = int(input())
*A, = map(int, input().split())
MOD = 10**9+7

ac = [0]*(N+1)
for i in range(N):
    ac[i+1] = ac[i]+A[i]
ans = 0

for i in range(1, N):
    ans += (ac[N]-ac[i])*A[i-1]
    ans %= MOD

print(ans)
