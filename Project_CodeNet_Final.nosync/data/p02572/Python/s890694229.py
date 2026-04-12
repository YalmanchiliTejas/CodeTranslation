n = int(input())
a = list(map(int, input().split()))
s = 0
ans = 0
for i in range(len(a)):
  s += a[i]
for i in range(len(a)-1):
  s -= a[i]
  ans += s*a[i]
  ans %= 1000000007
print(ans)