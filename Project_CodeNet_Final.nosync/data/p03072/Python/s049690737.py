N = int(input())
H = list(map(int, input().split()))

ans = 0
max_height = 0
for h in H:
  if h >= max_height:
    ans += 1
  max_height = max(h, max_height)

print(ans)