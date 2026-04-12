import numpy as np
h,w=map(int,input().split())
a=[input() for _ in range(h)]
a=np.asarray([list(s) for s in a if s!='.'*w]).T

h=len(a[0])
a=np.asarray([x for x in a if ''.join(x)!='.'*h]).T

for x in a:
  print(''.join(x))