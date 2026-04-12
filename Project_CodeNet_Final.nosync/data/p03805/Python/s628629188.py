import math
from collections import defaultdict
import itertools
def input_as_int():
    return tuple(map(int,input().split()))

N,M  = input_as_int()

path = defaultdict(lambda  :defaultdict(lambda :False))
for i in range(M):
    a,b = input_as_int()
    path[a][b] = path[b][a] = True

ans = 0
roots = itertools.permutations(list(range(2,N+1)))
for root in roots:
    fr = 1
    flag = True
    for to in root:
        if path[fr][to]:
            fr = to
        else:
            flag = False
            break
    if flag:
        ans += 1
print(ans)


