import itertools as it

MOD = 10**9 + 7
N = int(input())
a = list(map(int, input().split()))
s = list(it.accumulate(a))
ans = 0
for i in range(N - 1):
    ans += s[i] * a[i + 1]
    ans %= MOD
print(ans)