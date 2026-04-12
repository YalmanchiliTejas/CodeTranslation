import numpy as np
import sys
n = int(input())
h = np.array([int(x) for x in input().split()])
ans = 0
m = h[0]
for i in range(n):
	if m <= h[i]:
		ans += 1
		m = h[i]
print(ans)