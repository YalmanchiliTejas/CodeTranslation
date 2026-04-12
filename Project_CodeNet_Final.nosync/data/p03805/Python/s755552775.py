from itertools import permutations
n, m = map(int, input().split())
ab = [[] for i in range(n)]
for i in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    ab[a].append(b)
    ab[b].append(a)
cnt = 0
if n == 2:
    if 1 in ab[0]:
        print(1)
    else:
        print(0)
    exit()
for p in permutations(range(1, n)):
    if p[0] in ab[0]:
        flag = True
        for i in range(n - 2):
            if p[i + 1] not in ab[p[i]]:
                flag = False
                break
        if flag:
            cnt += 1
print(cnt)