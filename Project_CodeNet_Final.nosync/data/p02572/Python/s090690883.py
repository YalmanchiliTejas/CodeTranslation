n = int(input())
a = list(map(int, input().split()))
ans = 0
k = sum(a)
ans = 0
for i in range(n - 1):
  k -= a[i]
  ans += a[i] * k
ans = ans % (10 ** 9 + 7)
print(ans)