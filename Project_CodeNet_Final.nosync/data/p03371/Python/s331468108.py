A,B,C,X,Y = map(int, input().split())

if 2*C > A + B:
  print(A*X+B*Y)
else:
  if min(X,Y) == X and 2*C > B:
    print(2*C*X + B*(Y-X))
  elif min(X,Y) == Y and 2*C > A:
    print(2*C*Y + A*(X-Y))
  else:
    print(2*C*max(X,Y))