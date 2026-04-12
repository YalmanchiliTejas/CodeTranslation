N = int (input ())
A = [int (x) for x in input().split()]
S = sum (A)
X = 0
for i in range (N-1):
  X += A[i]*(S-A[i])
  S -= A[i]
  if X > 10**9+7:
    X = X%(10**9+7)
print (X)