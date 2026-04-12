import itertools

N, M = map(int, input().split())
lst = [set() for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    lst[a].add(b)
    lst[b].add(a)

ans = 0
for t in itertools.permutations(range(2, N + 1)):
    tmp = 1
    for x in t:
        if x not in lst[tmp]:
            break
        tmp = x
    else:
        ans += 1
print(ans)
