import bisect
N = int(input())
A = list()
for i in range(N):
  A.append(int(input()))
L = list()
for j in range(N-1, -1, -1):
  n = A[j]
  if(len(L) == 0):
    L.append(n)
  elif(L[-1] <= n):
    L.append(n)
  else:
    x = bisect.bisect_right(L, n)
    L[x] = n
print(len(L))