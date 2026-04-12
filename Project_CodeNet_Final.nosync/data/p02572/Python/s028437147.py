N = int(input())
A = list(map(int, input().split()))
tmp = sum(A[1:])
ans = 0
for i in range(N-1):
  ans += A[i]*tmp
  tmp -=A[i+1]
print(ans%(10**9+7))