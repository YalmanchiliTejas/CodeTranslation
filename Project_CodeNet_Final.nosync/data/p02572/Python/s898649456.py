N = int(input())
A = list(map(int, input().split()))

kMod = (10**9) + 7

ans = 0
s = 0

for a in A:
    ans += s * a
    s += a
    s %= kMod
    ans %= kMod
print(ans)
