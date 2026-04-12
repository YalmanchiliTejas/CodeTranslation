import math
K,A,B = map(int,input().split())
if A <= B:
  if K > A:
    print(-1)
  else:
    print(1)
else:
  n = (K-A)//(A-B)
  if n <= 0:
    print(1)
  else:
    if (A-B)*n+A >= K:
      print(2*n+1)
    else:
      print(2*n+3)