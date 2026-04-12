import sys
sys.setrecursionlimit(10**8)
def ii(): return int(sys.stdin.readline())
def mi(): return map(int, sys.stdin.readline().split())
def li(): return list(map(int, sys.stdin.readline().split()))
def li2(N): return [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
def dp2(ini, i, j): return [[ini]*i for _ in range(j)]
#import bisect #bisect.bisect_left(B, a)
from collections import defaultdict #d = defaultdict(int) d[key] += value
#from collections import Counter # a = Counter(A).most_common()
#from itertools import accumulate #list(accumulate(A))
'''
def f(n):
    if n % 2:
        return 3 * n + 1
    else:
        return n // 2

s = ii()
d = defaultdict(int)
d[s] = 1

while True:
    if d[f(x)] == 1:
        print()
    d[f(x)] += 1
    x = f(x)
'''

n = ii()
if n == 3 or n == 5 or n == 7:
    print('YES')
else:
    print('NO')


