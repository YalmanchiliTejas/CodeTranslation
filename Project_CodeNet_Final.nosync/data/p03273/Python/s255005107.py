import numpy as np
H,W = map(int,input().split())
l = []
for i in range(H):
    tmp = input()
    if tmp.count('.') != W:
        l.append(list(tmp))
    else:
      	H-=1
l = np.array(l).T.tolist()
ans = []
for i in l:
  if i.count('.') != H:
    ans.append(i)
for i in np.array(ans).T:
  print(''.join(i))
  