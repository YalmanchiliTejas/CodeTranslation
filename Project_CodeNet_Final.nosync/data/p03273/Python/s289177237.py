H,W = map(int,input().split())
L = []
for h in range(H):
  L.append(input())
  
X = [0]*W
Y = [0]*H

for h in range(H):
  for w in range(W):
    if L[h][w]=="#":
      X[w]=1
      Y[h]=1
      
for h in range(H):
  if Y[h]==1:
    for w in range(W):
      if X[w]==1:
        print(L[h][w] , end="")
    print()
        