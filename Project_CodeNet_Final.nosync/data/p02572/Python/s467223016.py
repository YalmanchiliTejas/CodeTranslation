N = int(input())
A = list(map(int, input().split()))

mod = 1000000007

S = [0]
for i in range(N):
    S.append((S[-1] + A[i]))

ans = 0
for i in range(N):
    sum = (S[N] - S[i + 1]) % mod
    ans += (A[i] * sum)
    ans %= mod

print(ans % mod)