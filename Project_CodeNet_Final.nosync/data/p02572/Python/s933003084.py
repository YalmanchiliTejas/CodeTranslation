n = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7
cumsum = [0] * (n + 1)
for i in range(n):
    cumsum[i + 1] = cumsum[i] + A[i]
    cumsum[i + 1] %= mod

ans = 0

for i in range(n - 1):
    ans += A[i] * (cumsum[-1] - cumsum[i + 1])
    ans %= mod
print(ans)
