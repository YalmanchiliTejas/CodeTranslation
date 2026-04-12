n = int(input())
h = list(map(int,input().split()))
max_h = h[0]
ans = 1
for i in range(1,n):
  if h[i]-h[i-1] >= 0 and max_h <= h[i]:
    ans += 1
  max_h = max(h[i],max_h)
print(ans)