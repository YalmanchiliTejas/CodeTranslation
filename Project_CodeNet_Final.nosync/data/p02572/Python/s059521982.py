N = int(input())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

ans = 0
s = sum(A)
for a in A:
    s -= a
    ans += s * a
    ans %= MOD

print(ans)