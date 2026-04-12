h,w=map(int,input().split())
h1=[0 for i in range(h)]
w1=[0 for i in range(w)]
m=[]
for i in range(h):
  a=input()
  m+=[a]
  if not "#" in a:
    h1[i]=1
    
for i in range(w):
  k=1
  for j in range(len(m)):
    if m[j][i]=="#":
      k=0
      break
  if k==1:
    w1[i]=1
    
for i in range(h):
  if h1[i]==1:
    continue
  ans=""
  for j in range(w):
    if w1[j]==1:
      continue
    ans+=m[i][j]
  print(ans)
  