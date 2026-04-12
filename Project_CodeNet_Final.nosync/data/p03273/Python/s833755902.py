H,W = map(int,input().split())
M = [""]*H
r = [False]*H
c = [False]*W

for i in range(H):
  M[i]=input()

for i in range(H):
  for j in range(W):
    if M[i][j]=="#":
      r[i]=True
      c[j]=True
      
for i in range(H):
  if r[i]:
    for j in range(W):
      if c[j]:
        print(M[i][j],end="")
    print()
    
