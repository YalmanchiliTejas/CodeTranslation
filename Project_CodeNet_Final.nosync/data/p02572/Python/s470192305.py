n = int(input())
a = list(map(int, input().split()))

result= 0
asum = sum(a)
for j in range(0,n):
  asum -= a[j]
  result += a[j]*(asum)

print(result%(10**9+7))
	