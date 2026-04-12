import numpy as np
n=int(input())
h=np.array(list(map(int,input().split())))
answer=0
for i in range(n):
  if np.all(h[:i] <= h[i]):
    answer+=1
print(answer)