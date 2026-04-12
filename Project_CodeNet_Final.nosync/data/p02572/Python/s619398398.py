n = int(input())
a = list(map(int,input().split()))
h = sum(a)
ans = 0
for i in range(n):
  h -= a[i]
  ans = (ans+a[i]*(h))%(10**9+7)
print(ans)
 

