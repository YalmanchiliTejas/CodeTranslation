N = int(input())
A = list(map(int,input().split()))

Sum = sum(A)
ans = 0
for i in range(N):
  Sum = Sum-A[i]
  AA = Sum*A[i]
  ans += AA
  ans = ans%(10**9 + 7)
print(ans)