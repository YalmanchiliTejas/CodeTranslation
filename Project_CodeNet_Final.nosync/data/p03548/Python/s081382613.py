X, Y, Z = map(int, input().split())

# 3 * n + 1 * (n-1) + 1 + 1
# Y * n + Z * (n-1) + Z + Z < X
# (Y + Z) * n + Z < X

import math
print(math.floor((X - Z) / (Y + Z)))