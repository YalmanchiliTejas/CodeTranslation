N = int(input())
H = list(map(int,input().split()))

ans = 1
for i in range(1, N):
  cnt = 0
  for j in range(i+1):
    if H[j] <= H[i]:
      cnt += 1
  if cnt == i+1:
    ans += 1
print(ans)