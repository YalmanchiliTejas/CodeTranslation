#%%
N, M = map(int, input().split())
a = [0] * M
b = [0] * M
for i in range(M):
    a[i], b[i] = map(int, input().split())

path = [[] for _ in range(N)]
for i in range(M):
    path[a[i]-1].append(b[i]-1)
    path[b[i]-1].append(a[i]-1)

import itertools

l = list(itertools.permutations(range(1, N)))

ans = 0

for i in range(len(l)):
    check = 0
    last = 0
    for j in range(len(l[i])):
        if l[i][j] in path[last]:
            last = l[i][j]
            pass
        else:
            check = 1
    if check == 0:
        ans += 1
            
print(ans)