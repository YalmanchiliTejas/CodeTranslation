
from heapq import heappush, heappop, heapify
from collections import deque, defaultdict, Counter
import itertools
from itertools import permutations, combinations
import sys
import bisect
import string
import math
import time
from fractions import gcd
#import random


def I(): return int(input())


def MI(): return map(int, input().split())


def LI(): return [int(i) for i in input().split()]


def LI_(): return [int(i)-1 for i in input().split()]


def StoI(): return [ord(i)-97 for i in input()]


def ItoS(nn): return chr(nn+97)


def input(): return sys.stdin.readline().rstrip()


def show(*inp, end='\n'):
    if show_flg:
        print(*inp, end=end)


YN = ['Yes', 'No']
MOD = 10**9+7
inf = float('inf')
IINF = 10**19
l_alp = string.ascii_lowercase
u_alp = string.ascii_uppercase
ts = time.time()
sys.setrecursionlimit(10**6)


# show_flg = False
show_flg = True


def main():
    N, M = MI()
    graph = [[] for i in range(N+1)]
    ans = 0

    for i in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    q = deque()
    q.append((1, set([1])))

    while len(q) != 0:
        edge, visited = q.popleft()
        nxt = graph[edge]

        if len(visited) == N:
            ans += 1

        for i, e in enumerate(nxt):
            if e not in visited:
                v = visited.copy()
                v.add(e)
                q.append((e, v))
            # else:
            #     print('stop', e, visited)

    print(ans)


if __name__ == '__main__':
    main()
