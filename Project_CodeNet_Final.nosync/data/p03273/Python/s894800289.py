h,w=map(int,input().split())
l=[list(input()) for _ in range(h)]
l=[i for i in l if i!=["."]*w]
h=len(l)
m=[]
for (i,j) in enumerate(zip(*l)):
  if j==tuple("." for _ in range(h)):
    m.extend([i])
for i in range(h):
  for j in range(w):
    if not j in m:
      print(l[i][j],end="")
  print()