n = int(input())
h = list(map(int, input().split()))

ans = 0
m = h[0]
for i in range(n):
  #print(m, h[i])
  if h[i] >= m:
    ans += 1
  if h[i] > m:
    m = h[i]
print(ans)