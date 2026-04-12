N=int(input())
A=[int(input()) for i in range(N)]

"""
import random
N=10
A=[random.randint(1,10) for i in range(N)]
print(A)
"""

import bisect
from collections import deque
D=deque([A[0]])

for a in A[1:]:
    if a<=D[0]:
        D.appendleft(a)

    else:
        x = bisect.bisect_right(D,a-1)
        D[x-1]=a

    #print(D)

print(len(D))
    

    
