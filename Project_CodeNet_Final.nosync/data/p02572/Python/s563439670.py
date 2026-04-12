n = int(input())
a = list(map(int, input().split()))
s = 0
c = sum(a)
for i in range(n-1):
  c -= a[i]
  s += a[i] * c
print(s % (10**9+7))