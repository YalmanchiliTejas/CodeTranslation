import numpy as np
N = int(input())
h = np.array(list(map(int, input().split())))

## 愚直にfor文組めばとりあえずすぐに解決できるけど...
count = 0
for i in range(1,N+1):
  mounts = h[:i]
  mounts_ = np.where(mounts<=h[i-1],0,1)
  if np.sum(mounts_) == 0:
    count += 1
print(count)