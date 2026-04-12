import sys
input = sys.stdin.readline
import itertools

N, M = map(int, input().split(' '))
path_map = {i:[] for i in range(1, N+1)}
for _ in range(M):
    a, b = map(int, input().split(' '))
    path_map[a].append(b)
    path_map[b].append(a)

ans = 0
for path in itertools.permutations(list(range(1, N+1))):
    if path[0] != 1:
        continue
    exist = True
    for i in range(N-1):
        if not path[i+1] in path_map[path[i]]:
            exist = False
            break
    if exist:
        ans += 1
print(ans)