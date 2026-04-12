N = int(input())
H = [int(n) for n in input().split()]
ans = 0
for i in range(N):
  t = max(H[:i+1])
  if t <= H[i]:
    ans += 1
print(ans)
