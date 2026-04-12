MOD = 10**9 + 7
n = int(input())
A = list(int(x) for x in input().split())
acc = [A[-1]]
for a in reversed(A[:-1]):
    acc.append((acc[-1] + a) % MOD)
acc.reverse()

ans = 0
for i in range(n - 1):
    ans += (A[i] * acc[i + 1]) % MOD
    ans %= MOD
print(ans)
