N,*L = map(int, open(0).read().split())
L.sort()
if N%2==0:
  A = L[:N//2]
  B = L[N//2:]
  a = 0
  b = -1
  m = 0
  n = 0
  p = B[0]
  for i in range(N-1):
    if i%2==0:
      m += p-A[a]
      p = A[a]
      a += 1
    else:
      m += B[b]-p
      p = B[b]
      b -= 1
  p = A[-1]
  a = 0
  b = -1
  for i in range(N-1):
    if i%2==0:
      n += B[b]-p
      p = B[b]
      b -= 1
    else:
      n += p-A[a]
      p = A[a]
      a += 1
  print(max(m,n))
else:
  A = L[:N//2]
  B = L[N//2:]
  a = 0
  b = -1
  m = 0
  n = 0
  p = B[0]
  for i in range(N-1):
    if i%2==0:
      m += p-A[a]
      p = A[a]
      a += 1
    else:
      m += B[b]-p
      p = B[b]
      b -= 1
  A = L[:N//2+1]
  B = L[N//2+1:]
  p = A[-1]
  a = 0
  b = -1
  for i in range(N-1):
    if i%2==0:
      n += B[b]-p
      p = B[b]
      b -= 1
    else:
      n += p-A[a]
      p = A[a]
      a += 1
  print(max(m,n))