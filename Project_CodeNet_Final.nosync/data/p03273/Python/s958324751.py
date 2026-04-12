H,W = map(int,input().split())
a=[]
for i in range(H):
  tmp=input()
  if tmp.count("#")==0:
    pass
  else:
    a.append(list(tmp))
else:
  H=len(a)
#print(a)
  
Ignore_tate = []
#たてNGリストアップ
for j in range(W):
  flag=True #除外対象である
  for k in range(H):
    if a[k][j]=="#":
      flag=False
      break
  if flag:
    Ignore_tate.append(j)

for p in range(H):
  str=""
  for q in range(W):
    if q not in Ignore_tate:
      str += a[p][q]
  print(str)