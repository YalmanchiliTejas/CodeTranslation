import sys
import time
import math
def inpl():
    return list(map(int, input().split()))
st = time.perf_counter()
# ------------------------------

X, Y, Z = map(int, input().split())
for i in range(1, 1001001001):
	if Y * i + Z * (i+1) > X:
		print(i-1)
		sys.exit()

# ------------------------------
ed = time.perf_counter()
print('time:', ed-st, file=sys.stderr)
