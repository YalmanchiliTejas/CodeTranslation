X,Y,Z = map(int,input().split())

L = X -2*Z
P = L // (Y+Z)
if L - P*(Y+Z) >= Y:
  print(P+1)
else:
  print(P)