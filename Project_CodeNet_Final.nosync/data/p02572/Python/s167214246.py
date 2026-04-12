n = int(input())
A = [*map(int, input().split())]
MOD = 10**9 + 7
ans = b = 0
for a in A:
    ans += a * b
    ans %= MOD
    b += a
print(ans)
