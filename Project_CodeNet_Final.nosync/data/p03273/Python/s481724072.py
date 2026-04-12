h,w=map(int,input().split())
a=[]
for i in range(h):
  temp=list(map(str,input()))
  a.append(temp)
temph=[]
tempw=[]
for i in range(h):
  for j in range(w):
    if a[i][j]!=".":
      break
  else:
    temph.append(i)
for i in range(w):
  for j in range(h):
    if a[j][i]!=".":
      break
  else:
    tempw.append(i)
import numpy as np
tempnp=np.array(a)
for i in range(len(temph)):
  tempnp=np.delete(tempnp, temph[i]-i, 0)
for i in range(len(tempw)):
  tempnp=np.delete(tempnp, tempw[i]-i, 1)
for i in range(h-len(temph)):
  print("".join(tempnp[i]))