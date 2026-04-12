#import string,itertools,fractions,heapq,re,array,bisect
#from math import *
#from collections import Counter
def rl(s): return xrange(len(s))

import sys
stdin = sys.stdin
def tokens(): return stdin.readline().strip().split()
def ints(): return map(int, tokens())
def int1(): return int( stdin.readline().strip() )

INF = 2147483647


S = tokens()[0]

if 'AC' in S:
    print "Yes"
else:
    print "No"

