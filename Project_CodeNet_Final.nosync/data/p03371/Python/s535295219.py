# import bisect
# import heapq
# from copy import deepcopy
# from collections import deque
# from collections import Counter
# from itertools import accumulate
# from itertools import permutations
# import numpy as np
# import math
# mod = 10**9 + 7

a,b,c,x,y = map(int,input().split())

mn = 10**10
for i in range(max(x,y) + 1):
    if x<=i<=y:
        total = 2*c*i + b*(y-i)
    elif y<=i<=x:
        total = 2*c*i + a*(x-i)

    else:
        total = 2*c*i + a*(x-i) + b*(y-i)

    mn = min(mn, total)

print(mn)