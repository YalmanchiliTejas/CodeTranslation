N = int(input())
A = list(map(int, input().split()))
m = A[0]
ans = 0
for a in A:
  m = max(m, a)
  if a == m:
    ans += 1
print(ans)
    