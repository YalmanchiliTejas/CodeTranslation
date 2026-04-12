N = int(input())
H = list(map(int, input().split()))
cur = H[0]
ans = 0
for i in range(N):
  if cur <= H[i]:
    ans += 1
    cur = H[i]
print(ans)