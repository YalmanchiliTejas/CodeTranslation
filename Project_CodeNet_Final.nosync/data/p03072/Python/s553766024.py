import numpy as np
N = int(input())
H = np.array(input().split(),dtype=np.int32)

H_cummax = np.maximum.accumulate(H)
answer = (H_cummax == H).sum()

print(answer)