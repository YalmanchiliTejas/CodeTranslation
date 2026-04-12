import numpy as np
h,w=map(int,input().split())
li=[]
for i in range(h):
  li.append(list(input()))
ll=[]
for i in li:
  if "#" in i:
    ll.append(i)
ll=np.array(ll).T.tolist()

out=[]
for i in ll:
  if "#" in i:
    out.append(i)
out=np.array(out).T.tolist()
for i in out:
  for j in i:
    print(j,end="")
  print()