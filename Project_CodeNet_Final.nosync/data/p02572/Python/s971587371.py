n = int(input())
l = list(map(int, input().split()))
mod = 1000000007
q = sum(l)
ans = 0
for i in range(len(l)):
    q -= l[i]
    ans += l[i] * q % mod
print(ans % mod)