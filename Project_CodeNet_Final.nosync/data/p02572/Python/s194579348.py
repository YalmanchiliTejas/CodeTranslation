N = int(input())
A = list(map(int, input().split()))
MOD, ans = 10**9 + 7, 0
Asum = sum(A)

for i in range(N):
    Asum -= A[i]
    ans = (ans + A[i] * (Asum % MOD)) %MOD

print(ans)