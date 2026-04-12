n = int(input())
h = [int(x) for x in input().split()]
ans = 1
m = h[0]
for i in range(1, n):
  if m <= h[i]:
    ans += 1
    m = h[i]

print(ans)
