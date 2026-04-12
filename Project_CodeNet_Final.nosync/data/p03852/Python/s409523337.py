from Queue import * # Queue, LifoQueue, PriorityQueue
from bisect import * #bisect, insort
from collections import * #deque, Counter,OrderedDict,defaultdict
#set([]) 
import math
import copy
import itertools
import string
import sys
myread = lambda : map(int,raw_input().split())
def solver():
    S = "aiueo"
    c = raw_input()
    if c in S:
        print "vowel"
    else:
        print "consonant"


if __name__ == "__main__":
    solver()
    