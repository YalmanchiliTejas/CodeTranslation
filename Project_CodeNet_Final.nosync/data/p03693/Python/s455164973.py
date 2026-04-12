import sys
import copy
import math
import bisect
import pprint
import bisect
from functools import reduce
from copy import deepcopy
from collections import deque

if __name__ == '__main__':
    a = [str(i) for i in input().split()]
    ans = "".join(a)

    if int(ans) % 4 ==0:
        print("YES")
    else:
        print("NO")
        
