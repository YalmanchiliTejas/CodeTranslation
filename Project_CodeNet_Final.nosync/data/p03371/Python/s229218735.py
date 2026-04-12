A,B,C,X,Y=map(int,input().split())
if A+B<=2*C:
  print(A*X+B*Y)
else:
  if X>=Y:
    print(min(2*Y*C+A*(X-Y),2*C*X))
  else:
    print(min(2*X*C+B*(Y-X),2*C*Y))