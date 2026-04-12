import numpy as np
h,w=map(int,input().split())
a=np.array([ list(input()) for i in range(h)])
count=0
d_w=[]
d_h=[]
for i in range(0,h):
  count=0
  for j in range(0,w):
    if a[i][j]==".":
      count+=1
  if count==w:
    d_w.append(i)
for i in range(0,w):
  count=0
  for j in range(0,h):
    if a[j][i]==".":
      count+=1
  if count==h:
    d_h.append(i)
a=np.delete(a,d_w,0)
a=np.delete(a,d_h,1)
for i in a:
  print("".join(i))