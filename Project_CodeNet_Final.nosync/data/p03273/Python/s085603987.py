#全然わからず完コピ
H,W=map(int,input().split())
a=[list(input()) for _ in range(H)]
h=[]
for i in range(H):
  if a[i]==['.']*W:
    h.append(i)

w=[]
for i in range(W):
  flag=0
  for j in range(H):
    if a[j][i]=='#':
      flag=1
      break
  if flag==0:
    w.append(i)
  
ans=[]
for i in range(H):
  if i not in h:
    r=[]
    for j in range(W):
      if j not in w:
        r.append(a[i][j])
    ans.append(r)

for i in range(len(ans)):
  print("".join(ans[i]))
