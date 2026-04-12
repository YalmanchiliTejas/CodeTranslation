A,B,C,X,Y = map(int,input().split())
if 2*C >= A+B:
  print(X*A+Y*B)
else:
  if X >= Y:
    if A > 2*C:
      print(2*X*C)
    else:
      print(2*Y*C + (X-Y)*A)
  else:
    if B > 2*C:
      print(2*Y*C)
    else:
      print(2*X*C+(Y-X)*B)

