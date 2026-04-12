X,Y,Z = map(int,input().split())
flag = False
for N in range(X):
  if ((Y+Z)*N+Z <= X < (Y+Z)*(N+1)+Z):
    flag = True
    break
print(N)