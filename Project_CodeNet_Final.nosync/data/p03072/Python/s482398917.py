N = int(input())
H = list(map(int, input().split()))
max_height = 0
ans = 0
for i in range(N):
  if H[i] == max(max_height, H[i]):
    max_height = H[i]
    ans += 1
  else:
    continue
print(ans)