n = int(input())
h = list(map(int,input().split()))
a = 0
t = 0
ans = 0
while t < n:
  if a <= h[t]:
    ans += 1
    a = h[t]
  t += 1
print(ans)