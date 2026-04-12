n=int(input())
a=list(map(int, input().split()))
l = [a[0]]
for i in range(1, n):
  l.append(l[i-1]+a[i])

ans = 0
for i in range(n):
  ans = (ans + (l[n-1] - l[i])*a[i]) % 1000000007

print(ans)