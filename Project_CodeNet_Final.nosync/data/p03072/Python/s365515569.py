N = int(input())
H = list(map(int,input().split()))
NowHeight = 0
ans = 0
for i in range(N):
  if NowHeight <= H[i]:
    NowHeight = H[i]
    ans += 1
print(ans)
