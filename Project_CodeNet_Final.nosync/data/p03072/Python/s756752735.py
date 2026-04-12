N = int(input())
Hs = list(map(int, input().split()))

max_h = 0
ans = 0
for height in Hs:
  if height >= max_h:
    ans += 1
    max_h = max(max_h, height)
  else: continue

print(ans)