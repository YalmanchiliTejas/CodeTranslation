import sys
import numpy as np
h,w = map(int,input().split())
a = [input() for i in range(h)]
a = [list(map(int,list(a[i].replace("#","1").replace(".","0")))) for i in range(h)]

aa = np.array(a)

tate = np.sum(aa,axis=0)
yoko = np.sum(aa,axis=1)

for i in range(len(tate)-1,-1,-1):
  if tate[i] == 0:
    aa = np.delete(aa,i,1)

for i in range(len(yoko)-1,-1,-1):
  if yoko[i] == 0:
    aa = np.delete(aa,i,0)

aa = np.where(aa == 0, ".", aa)
aa = np.where(aa == '1', "#", aa)

a = aa.tolist()

for i in range(len(a)):
  print(''.join(a[i]))