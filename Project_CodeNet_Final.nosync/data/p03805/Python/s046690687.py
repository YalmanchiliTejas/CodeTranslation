from itertools import permutations
n, m = map(int, input().split())
edge = set()

ans = 0
for _ in range(m):
    a, b = map(int, input().split())
    edge.add((a, b))

is_used = set([])
for per in permutations(range(2, n + 1)):
    flag = True
    if (1, per[0]) not in edge:
        continue
    for i in range(n - 2):
        if (per[i], per[i + 1]) not in edge and (per[i + 1], per[i]) not in edge:
            flag = False
            break
    if flag:
        ans += 1

print(ans)
