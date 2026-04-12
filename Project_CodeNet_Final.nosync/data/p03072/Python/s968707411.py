N = int(input())
H = [int(n) for n in input().split()]
ans = 0
m = 0
for i in range(N):
  if m <= H[i]:
    m = H[i]
    ans += 1
print(ans)
