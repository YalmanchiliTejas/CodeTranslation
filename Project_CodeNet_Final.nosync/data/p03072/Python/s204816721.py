N = int(input())
L = list(map(int, input().split()))
ans = 0
for i in range(N):
  if max(L[:i+1]) == L[i]:
    ans += 1
print(ans)
  