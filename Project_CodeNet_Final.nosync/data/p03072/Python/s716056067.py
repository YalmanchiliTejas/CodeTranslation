import numpy as np
N=int(input())
H=np.array(input().split(),dtype=np.int32)

H_cummax=np.maximum.accumulate(H)
print((H_cummax==H).sum())
