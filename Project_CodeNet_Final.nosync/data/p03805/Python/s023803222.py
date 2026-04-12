import itertools

N, M = map(int, input().split())
Paths = [list(map(int, input().split())) for i in range(M)]


points = [i for i in range(1, N+1)]
ans = 0

for i, v in enumerate(list(itertools.permutations(points))):
    if not v[0] == 1:
        continue
    for j in range(N-1):
        if sorted([v[j], v[j+1]]) not in Paths:
            break
    else:  # このelseの使い方覚える
        ans += 1


print(ans)