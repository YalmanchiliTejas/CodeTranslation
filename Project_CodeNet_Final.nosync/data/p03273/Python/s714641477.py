import numpy as np

h,w=map(int,input().split())
zentai=[list(input()) for i in range(h)]

for z in zentai[:]:
  if "#" not in z:
    zentai.remove(z)

tr=np.array(zentai)
tr=tr.T
tr=tr.tolist()

for z in tr[:]:
  if "#" not in z:
    tr.remove(z)

tr=np.array(tr)
tr=tr.T
tr=tr.tolist()

for i in tr:
  print("".join(i))