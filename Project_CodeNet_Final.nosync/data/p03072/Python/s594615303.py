N = int(input())
A = list(map(int,input().split()))
MAX = 0
ans = 0
for i in range(N):
  if MAX <= A[i]:
    ans += 1
  MAX = max(MAX,A[i])
print(ans)