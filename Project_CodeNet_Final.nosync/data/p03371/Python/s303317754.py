A,B,C,X,Y = map(int,input().split())

if A+B<=2*C:
  print(A*X+B*Y)
else:
  if X<=Y:
    print(min(2*C*X+B*(Y-X),2*C*Y))
  else:
    print(min(2*C*Y+A*(X-Y),2*C*X))