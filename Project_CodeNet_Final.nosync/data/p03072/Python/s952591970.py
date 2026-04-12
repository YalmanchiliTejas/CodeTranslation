n = int(input())
H = list(map(int, input().split()))

max_h = -1
ans = 0
for h in H:
  if h >= max_h:
    ans += 1
    max_h = h

print(ans)
