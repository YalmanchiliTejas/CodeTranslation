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
    a = int(input())
    ans = a*800 - 200*(a//15)
    print(ans)
