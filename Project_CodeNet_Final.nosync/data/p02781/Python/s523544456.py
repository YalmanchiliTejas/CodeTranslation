import math
def comb(n, r):
  if n >= r:
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
  else:
    return 0
N = int(input())
K = int(input())
A = []
ans = 0


for i in range(K):
  n = int(str(N)[0])
  dig = len(str(N)) - 1
  A.append([n, dig])
  N -= n * 10**dig
  if N == 0:
    break
#print(A)

for i in range(len(A)):
  if A[i][1] >= K-i:
    ans += comb(A[i][1], K-i) * 9 ** (K-i) 
#    print(ans)
  ans += (A[i][0]-1) * comb(A[i][1], K-i-1) * 9 ** (K-i-1)
#  print(ans)
if len(A) == K:
  ans += 1


print(ans)