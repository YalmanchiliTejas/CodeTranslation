from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
MOD = 10 ** 9 + 7

ans = 0
acc = [0] + list(accumulate(A))
for i, a in enumerate(A):
    ans += ((acc[-1] - acc[i + 1]) * a) % MOD
    ans %= MOD

print(ans % MOD)
