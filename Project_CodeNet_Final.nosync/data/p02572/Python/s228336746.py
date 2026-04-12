d = 10 ** 9 + 7
n = int(input())

a = list(map(int,input().split()))


s = 0
for i in range(n):
    s += a[i]
    s %= d

ans = 0

b = 0
for i in range(n):
    b += a[i] ** 2
    b %= d

ans = s ** 2 - b
ans %= d

if ans % 2 == 0:
    ans //= 2
else:
    ans += d
    ans //= 2

print(ans)
