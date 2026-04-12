A,B,C,X,Y = map(int,input().split())

if (A + B) <= 2 * C:
  print( A*X + B*Y)
else:
  if X >= Y:
    if A < 2 * C:
      print(A*(X-Y)+2*C*Y)
    else:
      print(2*C*X)
  else:
    if B < 2 * C:
      print(B*(Y-X)+2*C*X)
    else:
      print(2*C*Y)