H,W=map(int,input().split())
D=[]
c=[0]*W
n=[]
for i in range(H):
  a=input()
  d=0
  for j in range(W):
    if a[j]==".":
      c[j]+=1
      d+=1
  if d!=W:
    D.append(a)
for x in range(W):
  if c[x]==H:
    n.append(x)
for y in range(len(D)):
  for z in range(W):
    if z not in n:
      print(D[y][z],end="")
  print("")
