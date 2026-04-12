N,X = map(int, raw_input().split())
A = [0]*N
B = [0]*N
A[0] = 1
B[0] = 1
for i in range(1,N):
  A[i] = 2*A[i-1]+3
  B[i] = 2*B[i-1]+1

def f(N,X):
  if N==0:
    return 1
  if X<=1:
    return 0
  if X<=1+A[N-1]:
    return f(N-1, X-1)
  if X<=1+A[N-1]+1:
    return B[N-1]+1
  if X<=1+A[N-1]+1+A[N-1]:
    return B[N-1]+1+f(N-1, X-2-A[N-1])
  if X<=1+A[N-1]+1+A[N-1]+1:
    return 2*B[N-1]+1
  print N,X

print f(N,X)
