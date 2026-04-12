A,B,C,X,Y=map(int,input().split())
D,E=min(2*C,A),min(2*C,B)

if 2*C<A+B:
  print(2*C*min(X,Y)+((X-Y)*D if X>=Y else E*(Y-X)))
else:
  print(A*X+B*Y)
