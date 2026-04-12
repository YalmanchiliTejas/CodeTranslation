N = int(input())
H = list(map(int, input().split()))

ans = 1
high = H[0]
for i in range(1, N):
  if H[i] >= high:
    ans += 1
    high = H[i]
print(ans)