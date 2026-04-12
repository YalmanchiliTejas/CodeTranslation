MOD = 10**9+7

N = int(input())
A = list(map(int, input().split()))
tot = sum(A[1:])
ans = 0
for i in range(N-1):
    ans += A[i]*tot
    ans %= MOD
    tot -= A[i+1]
print(ans)
