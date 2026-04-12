_ = input()
MOD = 10**9 + 7
ans = b = 0
for a in map(int, input().split()):
    ans += a * b
    ans %= MOD
    b += a
print(ans)
