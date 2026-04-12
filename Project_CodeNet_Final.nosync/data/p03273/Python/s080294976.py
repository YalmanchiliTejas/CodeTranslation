h,w=map(int,input().split())
a=[input() for _ in range(h)]
res=[]
for i in range(h):
    if "#" not in a[i]:
      res.append(i)

resh=[]
h=len(a)
for i in range(w):
    for j in range(len(a)):
      if a[j][i]=="#":
        break
    else:
      resh.append(i)
for i in range(h):
  for j in range(w):
    if i not in res and j not in resh:
      print(a[i][j],end="")
  if i not in res:
    print("")