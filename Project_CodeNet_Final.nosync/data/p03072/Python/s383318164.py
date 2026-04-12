n = int(input())
h = list(map(int, input().split()))
ans = 1
hst = h[0]
for i in range(1, n):
  if h[i] >= hst:
    ans += 1
    hst = h[i]
print(ans)