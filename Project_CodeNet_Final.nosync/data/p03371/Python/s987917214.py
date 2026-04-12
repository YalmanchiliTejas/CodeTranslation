A,B,C,X,Y=map(int,input().split())
if A+B>2*C:
  if X>=Y:
    print(min(C*X*2,Y*2*C+((X-Y)*A)))
  else:
    print(min(C*Y*2,X*2*C+((Y-X)*B)))
else:
  print(A*X+B*Y)