N = int(input())
ans = 0
A = list(map(int, input().split()))
for i in range(N):
  if A[i] == max(A[:i+1]):
    ans += 1
print(ans)