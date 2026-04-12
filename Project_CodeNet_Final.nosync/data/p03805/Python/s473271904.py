from itertools import permutations

N, M = map(int, input().split())

E = []
for i in range(M):
    E.append(tuple(map(int, input().split())))

P = []
for p in permutations(range(2, N+1)):
    tmp = [1]
    tmp.extend(list(p))
    P.append(tmp)

ans = 0
for p in P:
    for i in range(1, N):
        exist = False
        for e in E:
            if set(e) == {p[i-1], p[i]}:
                exist = True
                break
        if exist is False:
            break
    else:
        if exist is False:
            break
    if exist:
        ans += 1

print(ans)
