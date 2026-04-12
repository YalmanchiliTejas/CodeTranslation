import numpy as np

H,W=map(int,input().split())
a=[list(map(int, list(input().replace('#','1').replace('.','0')))) for _ in range(H)]

a = np.array(a)

dellist=[]
for i in range(a.shape[0]):
  if a[i,:].sum()==0:
    dellist.append(i)
a = np.delete(a,dellist,0)
    
dellist=[]
for j in range(a.shape[1]):
  if a[:, j].sum()==0:
    dellist.append(j)
a = np.delete(a,dellist,1)

ans=[]
for i in range(a.shape[0]):
  tmp=''
  for j in range(a.shape[1]):
    if a[i][j]==1:
      tmp += '#'
    else:
      tmp += '.'
  ans.append(tmp)
  
for i in range(len(ans)):
  print(ans[i])