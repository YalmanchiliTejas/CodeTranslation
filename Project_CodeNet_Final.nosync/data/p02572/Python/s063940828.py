mod = 10**9 + 7

n = int(input())
a = [int(x) for x in input().split()]
ans = 0
sum = a[n-1]
for i in range(n-2, -1, -1):
    ans = (ans + sum * a[i]) % mod
    sum += a[i]
ans %= mod

print(ans)

