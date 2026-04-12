n = int(input())
a = list(map(int,input().split()))
h = sum(a)
ans = 0
for i in range(n):
  h -= a[i]
  ans += a[i]*(h)
print(ans%(10**9+7))
 

