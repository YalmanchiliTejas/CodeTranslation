N = int(input())
H = list(map(int, input().split()))

ans = 0
max_height = H[0]
for i in range(N):
  if max_height <= H[i]:
    ans += 1
    max_height = H[i]

print(ans)