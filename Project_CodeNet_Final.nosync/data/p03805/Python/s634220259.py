from collections import defaultdict
from itertools import permutations
N,M=map(int,input().split())
mat = [[0]*(1+N) for _ in range(1+N)]
for _ in range(M):
    a,b = map(int,input().split())
    mat[a][b] = 1
    mat[b][a] = 1
ans = 0
for tpl in permutations(range(2, 1+N), N-1):
    is_ok = 1
    tpl = [1] + list(tpl)
    for i in range(N-1):
        if mat[tpl[i]][tpl[i+1]] == 0:
            is_ok = 0
            break
    
    if is_ok:
        ans += 1
print(ans)
    