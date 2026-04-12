A,B,C,X,Y=map(int,input().split())
 
if A+B>2*C:
  if X>Y:
    print(min(A*abs(X-Y)+ min(X,Y)*C*2, max(X,Y)*C*2))
  else:
    print(min(B*abs(X-Y)+ min(X,Y)*C*2, max(X,Y)*C*2))
else:
  print(A*X+B*Y)