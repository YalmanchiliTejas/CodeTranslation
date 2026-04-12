N = int(input())
H = list(map(int, input().split()))

ans = 1
for i in range(1, N):
  if max(H[:i]) <= H[i]:
    ans += 1
print(ans)


