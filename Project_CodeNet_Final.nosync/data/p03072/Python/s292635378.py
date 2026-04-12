import numpy as np
N = int(input())
H = np.array(list(map(int, input().split())))
m = H[0]
ans = 0
for i in range(N):
    if H[i]>=m:
        ans = ans +1
        m = H[i]
print(ans)