n = int(input())
a = list(map(int, input().split()))
ans = 0
while max(a) >= n:
  t = sum(x//n for x in a)
  for i in range(n):
    g = a[i]//n
    a[i] += t - g - g*n
  ans += t
print(ans)