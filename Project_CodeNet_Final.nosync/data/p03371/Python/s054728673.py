##import sys
#import numpy as np
import math
#from fractions import Fraction
import itertools
from collections import deque
from collections import Counter
import heapq
from fractions  import gcd
#input=sys.stdin.readline
#import bisect
a,b,c,x,y=map(int,input().split())
if x<y:
    ans=min((a*x+b*y),2*x*c+b*(y-x),2*y*c)
    
else:
    ans=min((a*x+b*y),2*y*c+a*(x-y),2*x*c)
print(ans)