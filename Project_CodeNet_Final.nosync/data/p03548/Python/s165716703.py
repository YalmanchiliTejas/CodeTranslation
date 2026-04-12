X,Y,Z = map(int,input().split())

for n in range(X//Y,0,-1):
  if n*Y+(n+1)*Z <= X:
    print(n)
    exit()