N = int(input())
H = list(map(int, input().split()))

ans = 0
maxh = 0
for i in range(N):
  if maxh <= H[i]:
    ans += 1
  maxh = max(maxh, H[i])
  
print(ans)