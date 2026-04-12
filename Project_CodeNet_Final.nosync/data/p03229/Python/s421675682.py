N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
#print(A)

ans = 0
if N % 2 == 0:
  for i in range(N//2-1):
    ans -= A[i]*2
  ans += -A[N//2-1] + A[N//2]
  for i in range(N//2+1,N):
    ans += A[i]*2
else:
  ans1 = 0
  for i in range(N//2-1):
    ans1 -= A[i]*2
  ans1 += -A[N//2-1]-A[N//2]
  for i in range(N//2+1,N):
    ans1 += A[i]*2
  ans2 = 0
  for i in range(N//2):
    ans2 -= A[i]*2
  ans2 += A[N//2] + A[N//2+1]
  for i in range(N//2+2,N):
    ans2 += A[i]*2
  #print(ans1,ans2)
  ans = max(ans1,ans2)
print(ans)
