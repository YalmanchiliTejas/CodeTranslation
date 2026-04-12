h,w = map(int,input().split())
a=[list(input()) for i in range(h)]
b=[]
dl=[]
for i in a:
  if "#" in i:
    b.append(i)
for j in range(w):
  for i in range(len(b)):
    if b[i][j] == "#":
      break
    elif i == len(b)-1:
      dl.append(j)
dl.sort(reverse=True)
for i in dl:
  for j in range(len(b)):
    del b[j][i]
for c in b:
  print(*c,sep="")