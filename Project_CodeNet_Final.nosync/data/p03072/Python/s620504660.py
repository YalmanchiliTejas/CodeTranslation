n = int(input())
h = list(map(int, input().split()))

Max = 0
ans = 0

for i in range(n):
  if h[i]>=Max:
    ans += 1
  Max = max(h[i], Max)

print(ans)