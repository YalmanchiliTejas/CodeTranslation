from collections import defaultdict
from itertools import permutations
N, M = [int(i) for i in input().split()]

dd = defaultdict(list)
ans = 0
for _ in range(M):
    po = [int(i) for i in input().split()]
    dd[po[0]].append(po[1])
    dd[po[1]].append(po[0])
for route in permutations(range(1,N+1)):
    can = True
    if route[0] != 1:
        continue
    for i in range(N-1):
        if route[i+1] not in dd[route[i]]:
            can = False
            break
    if can:
        ans += 1

print(ans)