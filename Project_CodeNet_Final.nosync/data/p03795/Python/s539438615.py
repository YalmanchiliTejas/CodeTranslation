import sys
import math
N = int(input())
if N < 0 or N > 100:
    sys.exit()

print(N*800 - math.floor((N/15))*200)
