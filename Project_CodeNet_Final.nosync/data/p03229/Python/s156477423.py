N = int(input())
A = []
for _ in range(N):
  A.append(int(input()))
  
A.sort(reverse=True)

if N == 2:
  ans = A[0] - A[1]
#elif N == 3:
#  ans = max( 2*A[0] - A[1] - A[2], A[0] + A[1] - 2*A[2])
elif N % 2 == 0:
  m = N // 2
  ans = 2*sum(A[:m-1]) + A[m-1] - A[m] - 2*sum(A[m+1:])
else:
  m = N // 2
  ans1 = 2*sum(A[:m]) - A[m] - A[m+1] - 2*sum(A[m+2:])
  ans2 = 2*sum(A[:m-1]) + A[m-1] + A[m] - 2*sum(A[m+1:])
  ans = max(ans1,ans2)
print(ans)
    