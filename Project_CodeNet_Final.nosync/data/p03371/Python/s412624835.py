A,B,C,X,Y = map(int,input().split())

if A+B<=C*2:
  print(A*X+B*Y)

else:
  if X<=Y:
    d = Y-X
    print(min((Y-d)*2*C+B*d,Y*2*C))
  else:
    d = X-Y
    print(min((X-d)*2*C+A*d,X*2*C))