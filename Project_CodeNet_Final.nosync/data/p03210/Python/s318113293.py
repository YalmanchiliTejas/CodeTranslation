from __future__ import print_function
import numpy as np
import sys
import math,string,itertools,fractions,heapq,collections,re,array,bisect,copy,functools
# from itertools import accumulate
# from collections import deque
import random

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

n = int(input())
if n==3 or n==5 or n==7:
    print("YES")
else:
    print("NO")
