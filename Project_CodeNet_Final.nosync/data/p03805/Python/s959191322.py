from itertools import permutations
N, M = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(M)]

P = list(permutations([i for i in range(2, N + 1)]))
ans = 0
for p in P:
    flag = True
    for j in range(len(p) - 1):
        if j == 0:
            a = 1
            b = p[j]
            if [a, b] not in ab:
                flag = False
        a = min(p[j], p[j + 1])
        b = max(p[j], p[j + 1])
        if [a, b] not in ab:
            flag = False
    if flag:
        ans += 1
print(ans)
    