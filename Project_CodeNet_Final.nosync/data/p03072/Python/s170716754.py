n = int(input())
H = list(map(int, input().split()))
ans = 1
for i in range(1, n):
  if (H[i] >= max(H[:i])):
    ans += 1

print(ans)
