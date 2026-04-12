X,Y,Z=map(int,input().split())
 
for i in range(1,X):
  if (Y+Z)*i+Z > X:
    print(i-1)
    break