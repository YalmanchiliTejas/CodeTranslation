N, M = map(int, input().split())
edge = dict()

for i in range(M):
    a, b = map(int, input().split())
    if a in edge:
        edge[a].append(b)
    else:
        edge[a] = [b]
    if b in edge:
        edge[b].append(a)
    else:
        edge[b] = [a]

def search(now, gone):
    if len(gone) == N - 1:
        return 1

    s = 0
    for i in edge[now]:
        if i not in gone:
            hoge = gone.copy()
            hoge.add(now)
            s += search(i, hoge)
    return s

print(search(1, set()))