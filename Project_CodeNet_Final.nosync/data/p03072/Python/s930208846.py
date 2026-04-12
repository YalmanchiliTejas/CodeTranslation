n = int(input())
h = list(map(int, input().split()))
ans = 1
MAX = h[0]
for i in h[1:]:
  if i >= MAX:
    ans += 1
    MAX = i
print(ans)