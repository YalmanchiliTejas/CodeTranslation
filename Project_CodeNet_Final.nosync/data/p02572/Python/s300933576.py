N = int(input())
alist = list(map(int, input().split()))
import numpy as np
Sum_a = 0
Sum_j_list = np.cumsum(alist)
for i in range(N-1):
  Sum_j = int((Sum_j_list[N-1] - Sum_j_list[i]) % int(1e9+7))
  Sum_a += (alist[i] * Sum_j) % int(1e9+7)
print(int(Sum_a % int(1e9+7)))