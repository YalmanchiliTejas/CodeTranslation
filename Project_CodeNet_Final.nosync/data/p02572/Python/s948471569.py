n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

res = sum([a[i] ** 2 for i in range(n)])
s = sum(a)
ans = (s ** 2 - res) // 2
ans %= mod

print(ans)