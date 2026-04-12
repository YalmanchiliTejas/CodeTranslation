import numpy as np
N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
if N % 2 == 0:
  up = [-1,1]
  down = [-1,1]
else:
  up = [-1,-1]
  down = [1,1]
for i in range(1,N-1):
  if i % 2 == 0:
    up.append(-2)
    down.append(2)
  else:
    up.append(2)
    down.append(-2)
up.sort()
down.sort()
up = np.array(up)
down = np.array(down)
print(max(np.sum(up * A),np.sum(down * A)))