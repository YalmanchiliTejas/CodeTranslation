N = int(input())
H = [int(n) for n in input().split()]
ans = 0
for i in range(1, N+1):
  t = max(H[:i])
  if t <= H[i-1]:
    ans += 1
print(ans)
