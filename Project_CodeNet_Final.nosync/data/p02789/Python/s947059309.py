# ANSHUL GAUTAM
# IIIT-D

from math import *
from copy import *
from string import *				# alpha = ascii_lowercase
from random import *				# l.sort(key=lambda l1:l1[0]-l1[1]) => ex: sort on the basis difference
from sys import stdin
from sys import maxsize
from operator import *				# d = sorted(d.items(), key=itemgetter(1))
from itertools import *
from collections import Counter		# d = dict(Counter(l))
from collections import defaultdict # d = defaultdict(list)

'''

'''

def solve(l):
	n = len(l)
	

a,b = list(map(int, stdin.readline().rstrip().split()))
if(a == b):
	print('Yes')
else:
	print('No')
