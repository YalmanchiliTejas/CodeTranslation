H, W = list(map(int,input().split(' ')))
ar = []
for i in range(H):
  w = list(input())
  #print(set(w))
  if set(w) != {'.'}:
    ar.append(w)
    
#print(ar)  

import numpy as np
ar2 = np.array(ar)
ar2_T = ar2.T
ar = []
for i in ar2_T:
#  print(set(i))
  if set(i) != {'.'}:
    ar.append(i)

ar_T = np.array(ar).T
for i in ar_T:
  print(''.join(i))