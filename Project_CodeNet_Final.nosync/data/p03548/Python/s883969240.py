X,Y,Z=map(int,input().split())
ans=X//(Y+Z)
if X<ans*(Y+Z)+Z:
  print(ans-1)
else:  
  print(ans)