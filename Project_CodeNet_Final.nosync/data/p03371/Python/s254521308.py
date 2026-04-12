A,B,C,X,Y=map(int,input().split())
if A+B<=2*C:
  print(X*A+Y*B)
else:
  if X<=Y:
    print(min(2*Y*C,2*X*C+(Y-X)*B))
  else:
    print(min(2*X*C,(X-Y)*A+2*Y*C))