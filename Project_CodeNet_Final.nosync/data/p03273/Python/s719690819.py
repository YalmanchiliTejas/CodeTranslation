H,W=map(int,input().split())
c=[]
for i in range(H):
  ci=input()
  if ci=="."*W:
    continue
  c.append(ci+"#")
l=len(c)
k=[True]*(W+1)
for i in range(l):
  for j in range(W,-1,-1):
    k[j]=k[j] and (c[i][j]==".")

for i in range(l):
  for j in range(W,-1,-1):
    if k[j]:
      c[i]=c[i][0:j]+c[i][j+1:]
for i in range(l):
  print(c[i][:-1])