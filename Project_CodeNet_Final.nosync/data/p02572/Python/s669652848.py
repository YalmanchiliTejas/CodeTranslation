n = int(input())
a = list(map(int, input().split()))
ans = 0
mod = (10 ** 9 + 7)
total = sum(a)
for i in range(n):
    total -= a[i]
    ans = (ans + total * a[i]) % mod
print(ans)