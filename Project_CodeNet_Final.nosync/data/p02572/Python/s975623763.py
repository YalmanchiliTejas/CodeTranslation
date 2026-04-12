N = int(input())
A = list(map(int, input().split()))
cumsum = [0]
for i in range(N):
    cumsum.append(cumsum[-1] + A[i])

mod = 10**9 + 7
ans = 0

for i in range(N - 1):
    tmp = (A[i] % mod) * (cumsum[-1] - cumsum[i + 1])
    ans += (tmp % mod)

print(ans % mod)
