N = int(input())
A = [int(i) for i in input().split()]

MOD = 10 ** 9 + 7

tmp = 0
for a in A[1:]:
    tmp += a
    tmp %= MOD

ans = 0
for i in range(N - 1):
    ans += (A[i] * tmp) % MOD
    ans %= MOD

    tmp -= A[i + 1]

print(ans)