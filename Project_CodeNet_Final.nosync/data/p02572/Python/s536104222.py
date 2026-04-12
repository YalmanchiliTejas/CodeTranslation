N = int(input())
A = list(map(int, input().split()))
MOD = (10**9)+7

S = sum(A)
ans = 0
for i in range(N-1):
    a = A[i]
    S -= a
    ans += a * S % MOD

print(ans % MOD)