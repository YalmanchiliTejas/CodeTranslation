import math

N = int(input())
A = list(map(int, input().split()))

B = [{} for _ in range(N+1)]


for i in range(1,N+1):
  if i == 1:
    B[1][0] = 0
    B[1][1] = A[0]
  elif i == 2:
    B[2][1] = max(A[0],A[1])
    if N % 2 == 1:
      B[2][0] = 0
  else:
    if N % 2 == 0:
      for j in range(math.ceil((i-1)/2),(i+1)//2+1):
        m1 = B[i-2][j-1]+A[i-1] if j-1 in B[i-2] else -float('inf')
        m2 = B[i-1][j] if j in B[i-1] else -float('inf')
        B[i][j] = max(m1,m2)
    else:
      for j in range(math.ceil((i-2)/2),(i+1)//2+1):
        m1 = B[i-2][j-1]+A[i-1] if j-1 in B[i-2] else -float('inf')
        m2 = B[i-1][j] if j in B[i-1] else -float('inf')
        B[i][j] = max(m1,m2)
      

print(B[N][N//2])
