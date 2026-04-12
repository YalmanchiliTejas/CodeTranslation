n = int(input())
h = list(map(int, input().split()))
ans = 1
top = h[0]
for i in range(1, n):
  if h[i] >= top:
    ans += 1
  top = max(top,h[i])
print(ans)
