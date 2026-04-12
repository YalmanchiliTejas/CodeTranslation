X,Y,Z=map(int,input().split())
if X%(Y+Z)>=Z:
  print(X//(Y+Z))
else:
  print(X//(Y+Z)-1)