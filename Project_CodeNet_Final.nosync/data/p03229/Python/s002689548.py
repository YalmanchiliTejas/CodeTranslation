import numpy as np
n = int(input())
A =sorted([int(input()) for _ in range(n)])
l = n//2
if n%2:
  a = 2*sum(A[n-(l-1):]) + A[n-l] + A[n-(l+1)] - 2*sum(A[:n-(l+1)])
  b = 2*sum(A[n-l:]) - A[n-(l+1)] - A[n-(l+2)] - 2*sum(A[:n-(l+2)])
  print(max(a, b))
else:
  t = 2*sum(A[n-(l-1):]) + A[n-l] - A[n-(l+1)] - 2*sum(A[:n-(l+1)])
  print(t)