n = int(input())
mod = int(1e9+7)
ans, t = 0, 0
for a in list(map(int, input().split())):
    ans = (ans+a*t) % mod
    t += a

print(ans)
