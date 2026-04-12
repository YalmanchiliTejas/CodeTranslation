import random as rng
import itertools as it
import collections as col
import heapq as hq
import sys
import copy as cp
sys.setrecursionlimit(10**9)


def dump_impl(*objects):
    print(*objects, file=sys.stderr)


def dump_dummy(*objects):
    pass


dump = dump_impl if "DEBUG" in sys.argv else dump_dummy

N = int(input())
S = input()
K = int(input())
ans = []
SK = S[K-1]
for si in S:
    ans.append(si if si == SK else '*')
print(''.join(ans))
