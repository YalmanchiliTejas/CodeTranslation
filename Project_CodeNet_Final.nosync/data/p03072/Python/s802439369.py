N = int(input())
H = list(map(int, input().split()))

ans = 0
sh = H[0]
for h in H:
  if h >= sh:
    ans += 1
    sh = max(h, sh)
print(ans)