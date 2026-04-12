n = int(input())
a = list(map(int,input().split()))
x = 0
b = 0
for i in range(n-1):
  b += a[n-i-1]
  x += b*a[n-i-2]
  x = x % (10**9+7)
print(x)