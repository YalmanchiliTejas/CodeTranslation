N = int(input())
H = list(map(int, input().split()))

height = H[0]
ans = 1
for i in range(1, N):
  if H[i] >= height:
    ans += 1
    height = H[i]
print(ans)