import sys
import numpy as np
import math
import collections
import copy
import decimal
import itertools
from collections import deque 
from functools import reduce
from itertools import product
from itertools import combinations
 
# input = sys.stdin.readline
N = int(input())
An = list(map(int, input().split()))
An_l = list(itertools.accumulate(An))
An_l.insert(0, 0)
ans = 0
for i, A in enumerate(An):
    tt = An_l[-1] - An_l[i+1]
#     print(i, An_l[-1], An_l[i], tt)
    At = A * tt
#     print(A, tt, At)
    ans = (ans+At) % (10**9+7)
#     print(ans)
print(ans)