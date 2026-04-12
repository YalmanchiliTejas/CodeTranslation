from itertools import permutations

n, m = map(int, input().split())
graph = [set(map(lambda n: int(n) - 1, input().split())) for _ in range(m)]

per_list = permutations(i for i in range(1, n))

ans = 0

for per in per_list:
    for i in range(n - 1):
        target = {0, per[i]} if not i else {per[i - 1], per[i]}
        if target not in graph:
            break
    else:
        ans += 1

print(ans)
