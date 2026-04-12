
import math
import itertools
import statistics
#import numpy as np
import collections

#n = int(input())
x, y, z = list(map(int, input().split()))

x -= z
print(x//(y+z))