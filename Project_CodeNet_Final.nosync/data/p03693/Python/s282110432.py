
import math
import itertools
import statistics
#import collections

n = list(map(int, input().split()))
if (n[1]*10+n[2])%4==0:
    print("YES")
else:
    print("NO")