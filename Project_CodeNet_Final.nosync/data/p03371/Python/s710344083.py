A,B,C,X,Y = map(int,input().split())
Z = min(X,Y)
if ((A+B)*Z <= C*2*Z):
  if (X <= Y):
    if (B <= 2*C):
      print((A+B)*Z+B*(Y-Z))
    else:
      print((A+B)*Z+2*C*(Y-Z))
  else:
    if (A <= 2*C):
      print((A+B)*Z+A*(X-Z))
    else:
      print((A+B)*Z+2*C*(X-Z))
else:
  if (X <= Y):
    if (B <= 2*C):
      print(2*C*Z+B*(Y-Z))
    else:
      print(2*C*Z+2*C*(Y-Z))
  else:
    if (A <= 2*C):
      print(2*C*Z+A*(X-Z))
    else:
      print(2*C*Z+2*C*(X-Z))