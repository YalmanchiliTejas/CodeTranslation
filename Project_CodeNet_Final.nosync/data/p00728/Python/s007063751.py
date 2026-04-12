while True:
  N = int(input())
  if N == 0:
    break
  L = []
  for i in range(N):
    L.append(int(input()))
  L.sort()
  A = sum(L)
  print((A-L[0]-L[len(L)-1])//(N-2))
