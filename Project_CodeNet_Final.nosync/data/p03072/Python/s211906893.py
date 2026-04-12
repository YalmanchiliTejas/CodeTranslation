N = int(input())
H = list(map(int, input().split()))
h_max = H[0]
ans = 1
for i in range(1, N):
  if H[i] >= H[i-1] and h_max <= H[i]:
    h_max = H[i]
    ans += 1
print(ans)