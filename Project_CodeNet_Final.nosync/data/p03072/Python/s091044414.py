N = int(input())
H = list(map(int,input().split()))
if N == 1:
  print(1)
  exit()
ans = 1
MAX = H[0]
for i in range(1,N):
  if H[i] >= MAX:
    ans += 1
  MAX = max(MAX,H[i])
print(ans)