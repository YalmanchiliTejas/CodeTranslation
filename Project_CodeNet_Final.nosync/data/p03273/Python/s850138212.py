h,w=map(int,input().split())
a=[input() for i in range(h)]
yoko=[]
tate=[]
for i in range(h):
  for j in range(w):
    if a[i][j]=="#":
      tate.append(i)
      break
for i in range(w):
  for j in range(h):
    if a[j][i]=="#":
      yoko.append(i)
      break
for i in tate:
  l=[a[i][j] for j in yoko]
  l="".join(l)
  print(l)