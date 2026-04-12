import sys
sys.setrecursionlimit(10**8)
def ii(): return int(sys.stdin.readline())
def mi(): return map(int, sys.stdin.readline().split())
def li(): return list(map(int, sys.stdin.readline().split()))
def li2(N): return [list(map(int, sys.stdin.readline().split())) for i in range(N)]
def dp2(ini, i, j): return [[ini]*i for i2 in range(j)]
def dp3(ini, i, j, k): return [[[ini]*i for i2 in range(j)] for i3 in range(k)]
#import bisect #bisect.bisect_left(B, a)
#from collections import defaultdict #d = defaultdict(int) d[key] += value
#from collections import Counter # a = Counter(A).most_common()
#from itertools import accumulate #list(accumulate(A))

N, X = mi()
'''
def rec(level):
    if level == 0:
        return 'P'
    return 'B' + rec(level-1) + 'P' + rec(level-1) + 'B'

b = rec(N)
print(b)
'''
X -= 1
cnt = 0
level = N
while True:
    if level == 0:
        cnt += 1
        break
    half = 2**(level+1) - 2
    #print(level, half, cnt)
    if X == 0:
        break
    elif X == half * 2:
        cnt += 2**(level+1) - 1
        break
    elif X > half:
        cnt += 2**(level)
        X -= half + 1
    elif X == half:
        cnt += 2**(level)
        break 
    else:
        X -= 1
    level -= 1
print(cnt)