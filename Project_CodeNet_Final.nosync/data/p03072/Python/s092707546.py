n = int(input())
h = list(map(int, input().split()))
ans = 0
m = 0
for i in range(n):
  if h[i] >= m:
    ans += 1
    m = h[i]
print(ans)