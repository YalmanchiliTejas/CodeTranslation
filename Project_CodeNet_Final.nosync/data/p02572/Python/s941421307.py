from itertools import accumulate
MOD = 10 ** 9 + 7
N = int(input())
As = list(map(int, input().split()))

acc = [As[0]]
for i in range(1, N):
    tmp = acc[-1] + As[i]
    acc.append(tmp % MOD)

ans = 0
for i in range(N-1):
    tmp = As[i] * (acc[N-1] - acc[i])
    tmp %= MOD
    ans += tmp
    ans %= MOD
print(ans)
