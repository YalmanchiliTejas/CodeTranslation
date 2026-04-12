A,B,C,X,Y = list(map(int,input().split()))
  
if X < Y:
  if C*2 <= B:
    print(C*2*Y)
  elif C*2 <= (A+B):
    print(C*2*X + B*(Y-X))
  else:
    print(A*X + B*Y)
else:
  if C*2 <= A:
    print(C*2*X)
  elif C*2 <= (A+B):
    print(C*2*Y + A*(X-Y))
  else:
    print(A*X + B*Y)