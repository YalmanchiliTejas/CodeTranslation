h,w = map(int, input().split())
a = [input() for i in range(h)]
a = [i for i in a if i!="."*w]
import numpy as np
flag = [[int(j) for j in i.replace(".","0").replace("#","1")] for i in a]
flagx = np.sum(flag,axis=0) > 0
d = {0:".",1:"#"}
for i in a:
  for j,b in zip(i,flagx):
    if b:
      print(j, end="")
  print()