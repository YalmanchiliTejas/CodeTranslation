A,B,C,X,Y=map(int,input().split())
key=A/2+B/2
if C>=key:
  print(A*X+B*Y)
else:
  if X>=Y:
    Key=X-Y
    if Key*C*2<=Key*A:
      print(C*2*X)
    else:
      print(C*2*Y+A*Key)
  else:
    Key=Y-X
    if Key*C*2<=Key*B:
      print(C*2*Y)
    else:
      print(C*2*X+B*Key)