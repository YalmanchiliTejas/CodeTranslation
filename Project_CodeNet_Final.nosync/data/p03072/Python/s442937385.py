N = int(input())
H = list(map(int, input().split()))
H_max = 0
ans = 0

for i in range(N):
  if max(H[i], H_max) == H[i]:
    ans += 1
    H_max = H[i]
print(ans)