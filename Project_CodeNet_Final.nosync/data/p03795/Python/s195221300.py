import sys
#from collections import defaultdict, deque, Counter
#from bisect import bisect_left
#import heapq
#import math
#from itertools import groupby as gb
#from itertools import permutations as perm
#from itertools import combinations as comb
#from fractions import gcd
#import numpy as np

stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)
MIN = -10 ** 9
MOD = 10 ** 9 + 7
INF = float("inf")
IINF = 10 ** 18

n = int(stdin.readline().rstrip())
#l = list(map(int, stdin.readline().rstrip().split()))
#n,m = map(int, stdin.readline().rstrip().split())
#AB = [list(map(int, stdin.readline().rstrip().split())) for _ in range(n)]
ans = 800*n - (n//15)*200
print(ans)
