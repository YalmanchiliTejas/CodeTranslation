N = int(input())
H = list(map(int, input().split()))

ans = 0
max_h = H[0]

for h in H:
  if h >= max_h:
    ans += 1
    max_h = h

print(ans)