A,B,C,X,Y=map(int,input().split())

if 2*C<A+B:
  print(2*C*min(X,Y)+(min(2*C,A)*(X-Y) if X>=Y else min(2*C,B)*(Y-X)))
else:
  print(A*X+B*Y)
